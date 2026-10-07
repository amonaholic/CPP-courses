#include <iostream>

int main() {

    const float low_end = 18.0;
    const float high_end = 25.0;

    int input_count = 0; 
    int input_outside_reference_count = 0;
    float sum = 0.0; 
    float min; 
    float max;
    float input;
    
    while(true) {
        std::cout << "Enter a temperature: ";
        std::cin >> input;

        if(input == 0) {
            break;
        }

        if(input_count == 0) {
            min = input;
            max = input;
        }

        sum += input;
        input_count++;

        if(input > high_end || input < low_end) {
            input_outside_reference_count++;
        }

        if(input < min) {
            min = input;
        }

        if(input > max) {
            max = input;
        }
    }


    if(input_count == 0) {
        std::cout << "No temperatures entered";
    }
    else {
        std::cout << "Entered temperatures: " << input_count << std::endl;
        std::cout << "Summary of temperatures: " << sum << std::endl;
        std::cout << "Average temperature recorded: " << sum / float(input_count) << std::endl;
        std::cout << "Smallest temperature recorded: " << min << std::endl;
        std::cout << "Largest temperature recorded: " << max << std::endl;
        std::cout << "Number of temperatures outside of reference: " << input_outside_reference_count << std::endl;
        std::cout << "Percentage of recorded temperatures outside of reference: " << (float(input_outside_reference_count) / float(input_count)) * 100 << "%";
    }
   
}