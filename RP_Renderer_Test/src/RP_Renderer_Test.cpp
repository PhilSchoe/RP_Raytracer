// RP_Renderer_Test.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <fstream>

#include "glm/vec3.hpp"     // vec3
#include "RP_Renderer_API.h"


void writePPMFile( const std::string filename, const int width, const int height, const float* data )
{
    std::cout << "Writing ppm file " << filename << " with width: " << width << ", height: " << height << std::endl;

    std::ofstream outputFile;
    outputFile.open( filename, std::ios::out );

    outputFile << "P3\n" << width << " " << height << "\n255\n";
    for( int j = height - 1; j >= 0; j-- )
    {
        for( int i = 0; i < width * 3; i += 3 )
        {
            int index = i + j * width * 3;

            float gamma = 1.0f / 2.2f;

            int red   = int( 255.99f * pow(data[index],     gamma) );
            int green = int( 255.99f * pow(data[index + 1], gamma) );
            int blue  = int( 255.99f * pow(data[index + 2], gamma) );

            outputFile << red << " " << green << " " << blue << "\n";
        }
    }

    outputFile.close();
}


int main()
{
    std::cout << "Starting RP_Renderer_Test!\n" << std::endl;

    const int width  = 200;
    const int height = 100;
    const int size   = width * height * 3;

    const int samplesPerPixel = 100;

    float* image = new float[size];

    renderImage( width, height, samplesPerPixel, image );
    writePPMFile( "output/Test.ppm", width, height, image );

    delete[] image;

    std::cout << "\nStopping RP_Renderer_Test!\n";

    std::getchar();
}