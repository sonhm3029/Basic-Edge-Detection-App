#include "EdgeDectection.h"



int uint8(double& n)
{
    // chuyen so n tu double sang kieu int thuoc khoang [0;255]
    if (n > 255)
    {
        n = 255;
    }
    else if (n < 0)
    {
        n = 0;
    }
    else {
        n = (int)(n + 0.5);
    }
    return n;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
EdgeDectection::EdgeDectection(void)
{
    outputImg = 0;
}

EdgeDectection::~EdgeDectection(void)
{
    outputImg = 0;
}

Mat EdgeDectection::sobelDetection(Mat inputImg)
{
    // define Sobel operator mask
    int Mx[3][3] = { {-1, 0, 1},
                     {-2, 0, 2},
                     {-1, 0, 1}
    };
    int My[3][3] = { {-1, -2, -1},
                     {0, 0, 0},
                     {1, 2, 1}
    };
    int m = inputImg.rows;// so hang ma tran anh
    int n = inputImg.cols;//so cot ma tran anh

    //Mat outputImg(m, n, CV_8UC1, Scalar(0, 0, 255));
    inputImg.copyTo(outputImg);
    outputImg = 0;


    double Gx = 0, Gy = 0, G = 0;
    for (int i = 1; i < m - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    Gx += inputImg.at<uchar>(a + i, b + j) * Mx[a + 1][b + 1];
                    Gy += inputImg.at<uchar>(a + i, b + j) * My[a + 1][b + 1];
                }
            }
            G = sqrt(pow(Gx, 2) + pow(Gy, 2));
            if (G > 255) { G = 255; }
            if (G < 0) { G = 0; }
            outputImg.at<uchar>(i, j) = uint8(G) >= threshold ? 255 : 0;
            Gx = 0; Gy = 0; G = 0;
        }
    }

    //imshow("anh dau ra", outputImg);
    imwrite("result.png", outputImg);
    return outputImg;
}


Mat EdgeDectection::robertDetection(Mat inputImg)
{
        
        int m = inputImg.rows;// so hang ma tran anh
        int n = inputImg.cols;//so cot ma tran anh

        //Mat outputImg(m, n, CV_8UC1, Scalar(0, 0, 255));
        inputImg.copyTo(outputImg);
        outputImg = 0;

        int max = 255;

        //Roberts mask
        int Mx[2][2] = { {1, 0},
                         {0,-1},
        };
        int My[2][2] = { { 0, 1},
                         {-1, 0},
        };
        double Gx = 0, Gy = 0, G = 0;
        ////////////////////////////////////////////////
        //// do convolution image matrix and robert masks
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                for (int a = -1; a < 1; a++)
                {
                    for (int b = -1; b < 1; b++)
                    {
                        Gx += inputImg.at<uchar>(a + i, b + j) * Mx[a + 1][b + 1];
                        Gy += inputImg.at<uchar>(a + i, b + j) * My[a + 1][b + 1];
                    }
                }
                G = sqrt(pow(Gx, 2) + pow(Gy, 2));
                if (G > max) G = max;
                if (G < 0) G = 0;
                outputImg.at<uchar>(i, j) = uint8(G)>=threshold?255:0;
                Gx = 0; Gy = 0; G = 0;
            }
        }

        return outputImg;
}

Mat EdgeDectection::kirschDetection(Mat inputImg){
    int m = inputImg.rows;// so hang ma tran anh
    int n = inputImg.cols;//so cot ma tran anh

    //Mat outputImg(m, n, CV_8UC1, Scalar(0, 0, 255));
    Mat outputImg;
    inputImg.copyTo(outputImg);
    outputImg = 0;

    int max = 255;

    /* masks for kirsch operator */
    short mask_0[3][3] = {
      { 5, 5, 5},
      {-3, 0, -3},
      {-3, -3, -3} };
    short mask_1[3][3] = {
      {-3, 5, 5},
      {-3, 0, 5},
      {-3, -3, -3} };
    short mask_2[3][3] = {
      {-3, -3, 5},
      {-3, 0, 5},
      {-3, -3, 5} };
    short mask_3[3][3] = {
      {-3, -3, -3},
      {-3, 0, 5},
      {-3, 5, 5} };
    short mask_4[3][3] = {
      {-3, -3, -3},
      {-3, 0, -3},
      { 5, 5, 5} };
    short mask_5[3][3] = {
      {-3, -3, -3},
      { 5, 0, -3},
      { 5, 5, -3} };
    short mask_6[3][3] = {
      { 5, -3, -3},
      { 5, 0, -3},
      { 5, -3, -3} };
    short mask_7[3][3] = {
      { 5, 5, -3},
      { 5, 0, -3},
      {-3, -3, -3} };


    /* Convolve for all 8 directions */
  /* 0 direction */
    int a, b;
    double sum = 0;
    for (int i = 1; i < m - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            for (a = -1; a < 2; a++)
            {
                for (b = -1; b < 2; b++)
                {
                    sum = sum + inputImg.at<uchar>(i + a, j + b) * mask_0[a + 1][b + 1];
                }
            }
            if (sum > max) sum = max;
            if (sum < 0) sum = 0;
            if (sum > outputImg.at<uchar>(i, j))
                outputImg.at<uchar>(i, j) = sum;
            /* 1 direction */
            sum = 0;
            for (a = -1; a < 2; a++)
            {
                for (b = -1; b < 2; b++)
                {
                    sum = sum + inputImg.at<uchar>(i + a, j + b) * mask_1[a + 1][b + 1];
                }
            }
            if (sum > max) sum = max;
            if (sum < 0) sum = 0;
            if (sum > outputImg.at<uchar>(i, j)) outputImg.at<uchar>(i, j) = sum;
            /* 2 direction */
            sum = 0;
            for (a = -1; a < 2; a++)
            {
                for (b = -1; b < 2; b++)
                {
                    sum = sum + inputImg.at<uchar>(i + a, j + b) * mask_2[a + 1][b + 1];
                }
            }
            if (sum > max) sum = max;
            if (sum < 0) sum = 0;
            if (sum > outputImg.at<uchar>(i, j)) outputImg.at<uchar>(i, j) = sum;
            /* 3 direction */
            sum = 0;
            for (a = -1; a < 2; a++)
            {
                for (b = -1; b < 2; b++)
                {
                    sum = sum + inputImg.at<uchar>(i + a, j + b) * mask_3[a + 1][b + 1];
                }
            }
            if (sum > max) sum = max;
            if (sum < 0) sum = 0;
            if (sum > outputImg.at<uchar>(i, j)) outputImg.at<uchar>(i, j) = sum;
            /* 4 direction */
            sum = 0;
            for (a = -1; a < 2; a++)
            {
                for (b = -1; b < 2; b++)
                {
                    sum = sum + inputImg.at<uchar>(i + a, j + b) * mask_4[a + 1][b + 1];
                }
            }
            if (sum > max) sum = max;
            if (sum < 0) sum = 0;
            if (sum > outputImg.at<uchar>(i, j)) outputImg.at<uchar>(i, j) = sum;
            /* 5 direction */
            sum = 0;
            for (a = -1; a < 2; a++)
            {
                for (b = -1; b < 2; b++)
                {
                    sum = sum + inputImg.at<uchar>(i + a, j + b) * mask_5[a + 1][b + 1];
                }
            }
            if (sum > max) sum = max;
            if (sum < 0) sum = 0;
            if (sum > outputImg.at<uchar>(i, j)) outputImg.at<uchar>(i, j) = sum;
            /* 6 direction */
            sum = 0;
            for (a = -1; a < 2; a++)
            {
                for (b = -1; b < 2; b++)
                {
                    sum = sum + inputImg.at<uchar>(i + a, j + b) * mask_6[a + 1][b + 1];
                }
            }
            if (sum > max) sum = max;
            if (sum < 0) sum = 0;
            if (sum > outputImg.at<uchar>(i, j)) outputImg.at<uchar>(i, j) = sum;
            /* 7 direction */
            sum = 0;
            for (a = -1; a < 2; a++)
            {
                for (b = -1; b < 2; b++)
                {
                    sum = sum + inputImg.at<uchar>(i + a, j + b) * mask_7[a + 1][b + 1];
                }
            }
            if (sum > max) sum = max;
            if (sum < 0) sum = 0;
            if (sum > outputImg.at<uchar>(i, j)) outputImg.at<uchar>(i, j) = sum;
            sum = outputImg.at<uchar>(i, j);
            outputImg.at<uchar>(i, j) = uint8(sum) >= threshold ? 255 : 0;
            sum = 0;
        }
    }
    return outputImg;
}