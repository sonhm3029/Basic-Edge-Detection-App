#pragma once


#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>
#include <opencv2/core/types_c.h>
#include <opencv2/core/core_c.h>
#include <opencv2/core/core.hpp>
//#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <math.h>
#include <typeinfo>
#include <cstdio>
#include <stdio.h>
#include "EdgeDectection.h"




namespace Demo1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;
	using namespace cv;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::PictureBox^ pictureBox2;
	public:  static System::Drawing::Bitmap^ b;
	public:  Bitmap^ b2;
	public:  Image^ inIMG;
	public:		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();// input File Path to take the inputIMG
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TrackBar^ trackBar1;	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;


	public:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code	
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 68);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(490, 472);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(124, 47);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Load";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Location = System::Drawing::Point(574, 68);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(490, 472);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(340, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(137, 47);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Save";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::SystemColors::Control;
			this->trackBar1->Location = System::Drawing::Point(600, 17);
			this->trackBar1->Maximum = 255;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(221, 45);
			this->trackBar1->TabIndex = 5;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Control;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(946, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(43, 24);
			this->textBox1->TabIndex = 7;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"None", L"Sobel", L"Kirsch", L"Robert" });
			this->comboBox1->Location = System::Drawing::Point(159, 12);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(163, 33);
			this->comboBox1->TabIndex = 8;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(827, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 25);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Threshold:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(165, 552);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(134, 25);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Input Image";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(737, 552);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(152, 25);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Output Image";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1078, 598);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Basic Edge Detection";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
//////////////////////		            CONVERT CV::MAT TO BITMAP              ////////////////////////////////////////////////////////////////


		Bitmap^ Demo1::MyForm::ConvertMatToBitmap(cv::Mat matToConvert) {
			return gcnew Bitmap(matToConvert.cols, matToConvert.rows, matToConvert.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, IntPtr(matToConvert.ptr()));
		}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
////////////////////////          CONVERT FILE PATH IN SYSTEM::STRING TYPE TO C++ STRING TYPE      ////////////////////////////////////////////////////////////////////////////////////////
	

	private: char* ConvertStringtoChar(System::String^ str)
	{
		char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
		return str2;
	}



////////////////////////                    LOAD IMAGE BUTTON             //////////////////////////////////////////////////////////////////////


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// This button'll give permission to Load file by browser
	///		RESET PICTURE BOX AND DROPDOWN MENU			////////////////////////
	comboBox1->SelectedItem = nullptr;
	pictureBox2->Image = nullptr;
	///////////////////////////////////////////////////////////////////////////
	openFileDialog1->InitialDirectory = "C:\\Users\\ducma\\Desktop\\testImage";
	openFileDialog1->Filter = "Images (*.bmp;*.gif;*.jpg;*.jpeg;*.png)|"
		"*.bmp;*.gif;*.jpg;*.jpeg;*.png|"
		"Bitmaps (*.bmp)|*.bmp|"
		"GIFs (*.gif)|*.gif|"
		"JPEGs (*.jpg)|*.jpg;*.jpeg|"
		"PNGs (*.png)|*.png";

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		pictureBox1->Image = Image::FromFile(openFileDialog1->FileName);
	}
	else 
	{

	}
}


/////////////////////////////////////                    SAVE IMAGE           //////////////////////////////////////////////////////////////////////

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int var = Convert::ToInt32(textBox1->Text);
	string file = ConvertStringtoChar(openFileDialog1->FileName);
	Mat inputImg;
	inputImg = imread(file, 0);
	EdgeDectection test;///////////////////////////////////////              SUPPORT SAVING IMAGE CUZ SOME INCONVENIENT OF C++ IN DESIGN
	test.threshold = var;
	Mat img;
	if (comboBox1->SelectedItem->ToString() == "Sobel")
	{
		img = test.sobelDetection(inputImg);
	}
	else if (comboBox1->SelectedItem->ToString() == "Robert")
	{
		img = test.robertDetection(inputImg);
	}
	else if (comboBox1->SelectedItem->ToString() == "Kirsch")
	{
		img = test.kirschDetection(inputImg);
	}
	string x = ConvertStringtoChar(textBox1->Text);
	string fileToSave = "output" + x + ".png";
	imwrite(fileToSave, img);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
	saveFileDialog1->InitialDirectory = "D:\\outputImage";
	saveFileDialog1->Filter = "Png Images (*.png)|*.png|Jpeg Images(*.jpg)|*.jpg";
	saveFileDialog1->Filter += "|Bitmap Images(*.bmp)|*.bmp";

	string text = ConvertStringtoChar(textBox1->Text);
	saveFileDialog1->ShowDialog();
	inIMG = Image::FromFile("output"+textBox1->Text+".png");
	inIMG->Save(saveFileDialog1->FileName);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: System::Void Label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = trackBar1->Value.ToString();
	//chuyen gia tri cua threshold tu string sang int
		int var = Convert::ToInt32(textBox1->Text);
	/////////////////////////////////////////////////////////////////////////////////
		string check = ConvertStringtoChar(openFileDialog1->FileName);
		if (check == "")
		{
			//MessageBox::Show("Chua co du lieu dau vao");// kiem tra xem da co du lieu vao hay chua
			//textBox1->Text = "0";
		}
		else if (comboBox1->SelectedIndex == -1)
		{
			MessageBox::Show("Chua chon kieu loc");
		}
		else if(comboBox1->SelectedItem->ToString() == "Sobel") {
			string file = ConvertStringtoChar(openFileDialog1->FileName);
			Mat inputImg;
			inputImg = imread(file, 0);
			EdgeDectection test;
			test.threshold = var;
			Mat img = test.sobelDetection(inputImg);//////////////
			////////////////////////////////////
			////////////////////
			Mat testImg;
			cvtColor(img, testImg, COLOR_GRAY2BGR);
			System::Drawing::Graphics^ graphics = pictureBox2->CreateGraphics();
			System::IntPtr ptr(testImg.ptr());t
			/*loi o doan nay System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(testImg.cols, testImg.rows, testImg.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);*/
			b = gcnew System::Drawing::Bitmap(testImg.cols, testImg.rows, testImg.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			b2 = b;
			System::Drawing::RectangleF rect(0, 0, pictureBox2->Width, pictureBox2->Height);
			graphics->DrawImage(b, rect);
		}
		else if(comboBox1->SelectedItem->ToString() == "Robert") {
		string file = ConvertStringtoChar(openFileDialog1->FileName);
		Mat inputImg;
		inputImg = imread(file, 0);
		EdgeDectection test;
		test.threshold = var;
		Mat img = test.robertDetection(inputImg);//////////////
		////////////////////////////////////
		////////////////////
		Mat testImg;
		cvtColor(img, testImg, COLOR_GRAY2BGR);
		System::Drawing::Graphics^ graphics = pictureBox2->CreateGraphics();
		System::IntPtr ptr(testImg.ptr());
		/*loi o doan nay System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(testImg.cols, testImg.rows, testImg.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);*/
		b = gcnew System::Drawing::Bitmap(testImg.cols, testImg.rows, testImg.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
		b2 = b;
		System::Drawing::RectangleF rect(0, 0, pictureBox2->Width, pictureBox2->Height);
		graphics->DrawImage(b, rect);
		}
		else if (comboBox1->SelectedItem->ToString() == "Kirsch") {
			string file = ConvertStringtoChar(openFileDialog1->FileName);
			Mat inputImg;
			inputImg = imread(file, 0);
			EdgeDectection test;
			test.threshold = var;
			Mat img = test.kirschDetection(inputImg);//////////////
			////////////////////////////////////
			////////////////////
			Mat testImg;
			cvtColor(img, testImg, COLOR_GRAY2BGR);
			System::Drawing::Graphics^ graphics = pictureBox2->CreateGraphics();
			System::IntPtr ptr(testImg.ptr());
			/*loi o doan nay System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(testImg.cols, testImg.rows, testImg.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);*/
			b = gcnew System::Drawing::Bitmap(testImg.cols, testImg.rows, testImg.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			b2 = b;
			System::Drawing::RectangleF rect(0, 0, pictureBox2->Width, pictureBox2->Height);
			graphics->DrawImage(b, rect);
		}
		
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
//////////////////////////////////////////			COMBOBOX FOR DROP DOWD LIST SELECTION		/////////////////////////////////////////////////


private: System::Void comboBox1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = trackBar1->Value.ToString();
	int var = Convert::ToInt32(textBox1->Text);
	if (comboBox1->SelectedIndex == -1)
	{
		return;
	}
	if (comboBox1->SelectedItem->ToString() == "None")
	{
		pictureBox2->Image = pictureBox1->Image;
	}
	
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
