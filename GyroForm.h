#pragma once
#include <windows.h>
#include <xinput.h>
#include <cmath>
#pragma comment(lib, "Xinput.lib")



namespace GyroscopeGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	
	 

	/// <summary>
	/// Summary for GyroForm
	/// </summary>                                                                                                                                                             
	public ref class GyroForm : public System::Windows::Forms::Form
	{
	public:
	

		GyroForm(void)
		{
			InitializeComponent();

			// This makes arduino and VS talk to each other
			serialPort = gcnew System::IO::Ports::SerialPort("COM4", 9600);//same speed as IDE serial monitor : // connects to the 
			serialPort->ReadTimeout = 100;
		 
			
			// make a stopwatch, actiavtes every 10ms, calls updateTimerTick funciton down there
			updateTimer = gcnew Timer();
			updateTimer->Interval = 30;
			updateTimer->Tick += gcnew EventHandler(this, &GyroForm::updateTimer_Tick);
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GyroForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		System::IO::Ports::SerialPort^ serialPort;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;

		Timer^ updateTimer;
	private:
		
	
		
		

		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(188, 373);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(515, 79);
			this->label1->TabIndex = 0;
			this->label1->Text = L"X Acceleration: ";
			this->label1->Click += gcnew System::EventHandler(this, &GyroForm::label1_Click_1);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(188, 502);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(515, 79);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Y Acceleration: ";
			this->label2->Click += gcnew System::EventHandler(this, &GyroForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(187, 613);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(560, 85);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Z Acceleration: ";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(46, 819);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(283, 81);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Connect";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GyroForm::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(493, 102);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(687, 147);
			this->label4->TabIndex = 4;
			this->label4->Text = L"WARNING";
			this->label4->Visible = false;
			this->label4->Click += gcnew System::EventHandler(this, &GyroForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(871, 581);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(70, 25);
			this->label5->TabIndex = 5;
			this->label5->Text = L"label5";
			this->label5->Click += gcnew System::EventHandler(this, &GyroForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(874, 621);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 25);
			this->label6->TabIndex = 6;
			this->label6->Text = L"label6";
			// 
			// GyroForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1214, 956);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"GyroForm";
			this->Text = L"GyroForm";
			this->Load += gcnew System::EventHandler(this, &GyroForm::GyroForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	

	private: System::Void updateTimer_Tick(Object^ sender, EventArgs^ e) {
		try {
			XINPUT_STATE controller;
			DWORD result = XInputGetState(0, &controller);


			float LeftStick = controller.Gamepad.sThumbLX;
			float RightStick = controller.Gamepad.sThumbRX; 

			
			label6->Text = "Right Stick : " + RightStick.ToString();
			label5->Text = "Left Stick: " + LeftStick.ToString();

			if (abs(LeftStick) <= 8000) {
				LeftStick == 0; 
			}
			else {
				if (LeftStick >= 30000 || LeftStick <= -30000) {
					serialPort->WriteLine("A");
				}
			}

			if (abs(RightStick) <= 8000) {
				RightStick == 0;
			}
			else {
				if (RightStick >= 30000 || RightStick <= -30000) {
					
				}
			}


			
			
			

			String^ line = serialPort->ReadLine(); // takes line from serial monitor from Arduino IDE  
			array<String^>^ parts = line->Split(','); //Splits up line based on commas 
		 

			if (parts->Length >= 4) {
				label1->Text = "X Acceleration: " + parts[0] + "g";
				label2->Text = "Y Acceleration: " + parts[1] + "g";
				label3->Text = "Z Acceleration: " + parts[2] + "g";

				String^ fallingStatus = parts[3]->Trim(); // this tells us if drone falling or not 

				if (fallingStatus == "Falling") {
					label4->Visible = true;
				}
				else {
					label4->Visible = false;
				}


			}
		}
		catch (TimeoutException^) {

		}





	}
	private: System::Void GyroForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		try {
			serialPort->Open(); 
			 
			updateTimer->Start(); 
			button1->Enabled = false; 
			
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error connecting: " + ex->Message); 
		}
	}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
