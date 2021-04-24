#include "helpers.h"
#include <math.h>

float roundingUp(float);
float limit(float);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Goes to through each pixel, takes the average of the RGB values and assigns the average value to each RGB.
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            // Calculating the average of R, G, and B of each pixel.
            float avg = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0; 
            avg = roundingUp(avg);
            
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImg[height][width]; // Creating a new image of the same dimensions of the given image.
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = (width - 1), k = 0 ; j >= 0 ; j--, k++)
        {
            newImg[i][k] = image[i][j]; //Making a reflection of the image in the new image horizontally.
        }
    }
    
    for (int x = 0 ; x < height ; x++)
    {
        for (int y = 0 ; y < width ; y++)
        {
            image[x][y] = newImg[x][y]; // Copy the new image into the original image.
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImg[height][width]; // Creating a new image of the same dimensions of the given image.
    for (int x = 0 ; x < height ; x++)
    {
        for (int y = 0 ; y < width ; y++)
        {
            newImg[x][y] = image[x][y];
        }
    }
    
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            float sumRed = 0.0, sumBlue = 0.0, sumGreen = 0.0;
            int pixCount = 0;
            for (int k = -1 ; k <= 1 ; k++)
            {
                for (int l = -1 ; l <= 1 ; l++)
                {
                    if ((i + k >= 0 && j + l >= 0) && (i + k < height && j + l < width))
                    {
                        pixCount++;
                        sumRed = sumRed + newImg[i + k][j + l].rgbtRed;
                        sumGreen = sumGreen + newImg[i + k][j + l].rgbtGreen;
                        sumBlue = sumBlue + newImg[i + k][j + l].rgbtBlue;
                    }
                }
            }
            image[i][j].rgbtRed = roundingUp(((sumRed)) / (float) pixCount);
            image[i][j].rgbtGreen = roundingUp((sumGreen) / (float) pixCount);
            image[i][j].rgbtBlue = roundingUp((sumBlue) / (float) pixCount);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    
    return;
}

float roundingUp(float num)
{
    if ((num - floor(num) < 0.5))
    {
        return (floor(num));
    }
    else
    {
        return (ceil(num));
    }
}

float limit(float num)
{
    if (num > 255)
    {
        return (255.0);
    }
    return num;
}