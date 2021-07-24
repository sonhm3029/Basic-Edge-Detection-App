#include "MyForm.h"
#include <array>
using namespace System;
using namespace System::Windows::Forms;
//using namespace std;


[STAThread]
void Main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Demo1::MyForm form;
	Application::Run(% form);
}
