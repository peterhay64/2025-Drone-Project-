#include "GyroForm.h" // The class for the new window 


using namespace System;
using namespace System::Windows::Forms; 

void main(array<String^>^ args) {
	
	// opens the new window in the windows 11 style, keeps it open until closed 
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	GyroscopeGUI::GyroForm form; 
	Application::Run(% form); 



}



