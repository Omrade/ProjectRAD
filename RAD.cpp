#include "RAD.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ProjectRAD::RAD form;
	Application::Run(% form);
}

System::Void ProjectRAD::RAD::файлToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	return System::Void();
}

System::Void ProjectRAD::RAD::действияToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void ProjectRAD::RAD::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Данная программа ипользуется для учёта радиоэлектронных компонентов,\tа так же для создания шаблонов их количества на платах");
	return System::Void();
}

System::Void ProjectRAD::RAD::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void ProjectRAD::RAD::groupBox1_Enter(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void ProjectRAD::RAD::dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	return System::Void();
}

