
#include <iostream>
#include <string>
#include <cstdint>
#include <fstream>
#include <vector>

void read_mnist_cv(const char* image_filename, const char* label_filename);

class Dataset{
		uint8_t image_col{};
		uint8_t image_row{};
		uint8_t *label_arr;
public:
		Dataset(uint8_t col, uint8_t row, uint8_t *label)
		{
				image_col = col;
				image_row = row;
				label_arr = label;

		}
};

int main()
{
		std::string base_dir = "/home/sarah/Projects/Coding/cpp/ANN/Artificial_Neural_Net/";
		std::string img_path = base_dir + "../MINST/training/train-images-idx3-ubyte";
		std::string label_path = base_dir + "../MINST/training/train-labels-idx1-ubyte";

		read_mnist_cv(img_path.c_str(), label_path.c_str());

		//finish writing paths for read_mnist_cv then confirm working\
		//if working start on ann and plan out rest of project
		//if not find a way to properly read the dataset
}


// Source - https://stackoverflow.com/a/52406407
// Posted by Jayhello, modified by community. See post 'Timeline' for change history
// Retrieved 2026-09-27, License - CC BY-SA 4.0

uint32_t swap_endian(uint32_t val) {
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
    return (val << 16) | (val >> 16);
}

void read_mnist_cv(const char* image_filename, const char* label_filename){
    // Open files
    std::ifstream image_file(image_filename, std::ios::in | std::ios::binary);
    std::ifstream label_file(label_filename, std::ios::in | std::ios::binary);

    // Read the magic and the meta data
    uint32_t magic;
    uint32_t num_items;
    uint32_t num_labels;
    uint32_t rows;
    uint32_t cols;

    image_file.read(reinterpret_cast<char*>(&magic), 4);
    magic = swap_endian(magic);
    if(magic != 2051){
			std::cout<<"Incorrect image file magic: "<<magic<<std::endl;
        return;
    }

    label_file.read(reinterpret_cast<char*>(&magic), 4);
    magic = swap_endian(magic);
    if(magic != 2049){
			std::cout<<"Incorrect image file magic: "<<magic<<std::endl;
        return;
    }

    image_file.read(reinterpret_cast<char*>(&num_items), 4);
    num_items = swap_endian(num_items);
    label_file.read(reinterpret_cast<char*>(&num_labels), 4);
    num_labels = swap_endian(num_labels);
    if(num_items != num_labels){
			std::cout<<"image file nums should equal to label num"<<std::endl;
        return;
    }

    image_file.read(reinterpret_cast<char*>(&rows), 4);
    rows = swap_endian(rows);
    image_file.read(reinterpret_cast<char*>(&cols), 4);
    cols = swap_endian(cols);

	std::cout<<"image and label num is: "<<num_items<<std::endl;
	std::cout<<"image rows: "<<rows<<", cols: "<<cols<<std::endl;

    char label;
    char* pixels = new char[rows * cols];

    for (int item_id = 0; item_id < num_items; ++item_id) {
        // read image pixel
        image_file.read(pixels, rows * cols);
        // read label
        label_file.read(&label, 1);

        std::string sLabel = std::to_string(int(label));
		//std::cout<<"lable is size: "<<sLabel.length()<<std::endl;
        /* convert it to cv Mat, and show it
        cv::Mat image_tmp(rows,cols,CV_8UC1,pixels);
        // resize bigger for showing
        cv::resize(image_tmp, image_tmp, cv::Size(100, 100));
        cv::imshow(sLabel, image_tmp);
        cv::waitKey(0); */ 
    }


    delete[] pixels;
}
