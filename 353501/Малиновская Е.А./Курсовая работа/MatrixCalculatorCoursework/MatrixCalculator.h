#pragma once
#include "MatrixFunctions.h"
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class MatrixCalculator : public System::Windows::Forms::Form
	{
		int rows1M = 3;
		int columns1M = 3;
		int rows2M = 3;
		int columns2M = 3;
		array<array<TextBox^>^>^ textBoxes1M;
		array<array<TextBox^>^>^ textBoxes2M;
		array<array<TextBox^>^>^ textBoxesRM;
		array<Button^>^ buttons;

	public:
		MatrixCalculator()
		{
			InitializeComponent();
			textBoxes1M = gcnew array<array<TextBox^>^>(3);
			textBoxes1M[0] = gcnew array<TextBox^>(3) { text11Box, text12Box, text13Box };
			textBoxes1M[1] = gcnew array<TextBox^>(3) { text21Box, text22Box, text23Box };
			textBoxes1M[2] = gcnew array<TextBox^>(3) { text31Box, text32Box, text33Box };

			textBoxes2M = gcnew array<array<TextBox^>^>(3);
			textBoxes2M[0] = gcnew array<TextBox^>(3) { text211Box, text212Box, text213Box };
			textBoxes2M[1] = gcnew array<TextBox^>(3) { text221Box, text222Box, text223Box };
			textBoxes2M[2] = gcnew array<TextBox^>(3) { text231Box, text232Box, text233Box };

			textBoxesRM = gcnew array<array<TextBox^>^>(3);
			textBoxesRM[0] = gcnew array<TextBox^>(3) { textR11Box, textR12Box, textR13Box };
			textBoxesRM[1] = gcnew array<TextBox^>(3) { textR21Box, textR22Box, textR23Box };
			textBoxesRM[2] = gcnew array<TextBox^>(3) { textR31Box, textR32Box, textR33Box };
			buttons = gcnew array<Button^>(12) { button0, button1, button2, button3, button4, button5, button6, button7, button8, button9, buttonMinus, buttonDelete };
		}

	protected:
		~MatrixCalculator()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Panel^ ModePanel;
	private: System::Windows::Forms::Panel^ FunctionPanel;
	private: System::Windows::Forms::Panel^ MatrixPanel;
	private: System::Windows::Forms::Panel^ ResultPanel;
	private: System::Windows::Forms::Panel^ SymbolPanel;
	private: System::Windows::Forms::Label^ modeLabel;
	private: System::Windows::Forms::RadioButton^ twoMatrixMode;
	private: System::Windows::Forms::RadioButton^ oneMatrixMode;
	private: System::Windows::Forms::Button^ button0;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Button^ buttonMinus;
	private: System::Windows::Forms::Button^ buttonDot;
	private: System::Windows::Forms::Label^ dimLabel1;
	private: System::Windows::Forms::Label^ dimLabel2;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ transposeButton;
	private: System::Windows::Forms::Button^ inverseButton;
	private: System::Windows::Forms::Button^ findDetButton;
	private: System::Windows::Forms::TextBox^ text33Box;
	private: System::Windows::Forms::TextBox^ text32Box;
	private: System::Windows::Forms::TextBox^ text31Box;
	private: System::Windows::Forms::TextBox^ text23Box;
	private: System::Windows::Forms::TextBox^ text22Box;
	private: System::Windows::Forms::TextBox^ text21Box;
	private: System::Windows::Forms::TextBox^ text13Box;
	private: System::Windows::Forms::TextBox^ text12Box;
	private: System::Windows::Forms::TextBox^ text11Box;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ text233Box;
	private: System::Windows::Forms::TextBox^ text232Box;
	private: System::Windows::Forms::TextBox^ text231Box;
	private: System::Windows::Forms::TextBox^ text223Box;
	private: System::Windows::Forms::TextBox^ text222Box;
	private: System::Windows::Forms::TextBox^ text221Box;
	private: System::Windows::Forms::TextBox^ text213Box;
	private: System::Windows::Forms::TextBox^ text212Box;
	private: System::Windows::Forms::TextBox^ text211Box;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ findButton;
	private: System::Windows::Forms::ComboBox^ comboBoxOperator;
	private: System::Windows::Forms::TextBox^ textR33Box;
	private: System::Windows::Forms::TextBox^ textR32Box;
	private: System::Windows::Forms::TextBox^ textR31Box;
	private: System::Windows::Forms::TextBox^ textR23Box;
	private: System::Windows::Forms::TextBox^ textR22Box;
	private: System::Windows::Forms::TextBox^ textR21Box;
	private: System::Windows::Forms::TextBox^ textR13Box;
	private: System::Windows::Forms::TextBox^ textR12Box;
	private: System::Windows::Forms::TextBox^ textR11Box;
	private: System::Windows::Forms::Label^ labelResult;
	private: System::Windows::Forms::Label^ warningLabel;
	private: System::Windows::Forms::Label^ detLabel;
	private: System::Windows::Forms::Label^ fieldsLabel;

#pragma region Windows Form Designer generated code

		   void InitializeComponent(void)
		   {
			   this->ModePanel = (gcnew System::Windows::Forms::Panel());
			   this->twoMatrixMode = (gcnew System::Windows::Forms::RadioButton());
			   this->oneMatrixMode = (gcnew System::Windows::Forms::RadioButton());
			   this->modeLabel = (gcnew System::Windows::Forms::Label());
			   this->FunctionPanel = (gcnew System::Windows::Forms::Panel());
			   this->transposeButton = (gcnew System::Windows::Forms::Button());
			   this->inverseButton = (gcnew System::Windows::Forms::Button());
			   this->findDetButton = (gcnew System::Windows::Forms::Button());
			   this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->dimLabel2 = (gcnew System::Windows::Forms::Label());
			   this->dimLabel1 = (gcnew System::Windows::Forms::Label());
			   this->MatrixPanel = (gcnew System::Windows::Forms::Panel());
			   this->fieldsLabel = (gcnew System::Windows::Forms::Label());
			   this->warningLabel = (gcnew System::Windows::Forms::Label());
			   this->comboBoxOperator = (gcnew System::Windows::Forms::ComboBox());
			   this->findButton = (gcnew System::Windows::Forms::Button());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->text233Box = (gcnew System::Windows::Forms::TextBox());
			   this->text232Box = (gcnew System::Windows::Forms::TextBox());
			   this->text231Box = (gcnew System::Windows::Forms::TextBox());
			   this->text223Box = (gcnew System::Windows::Forms::TextBox());
			   this->text222Box = (gcnew System::Windows::Forms::TextBox());
			   this->text221Box = (gcnew System::Windows::Forms::TextBox());
			   this->text213Box = (gcnew System::Windows::Forms::TextBox());
			   this->text212Box = (gcnew System::Windows::Forms::TextBox());
			   this->text211Box = (gcnew System::Windows::Forms::TextBox());
			   this->text33Box = (gcnew System::Windows::Forms::TextBox());
			   this->text32Box = (gcnew System::Windows::Forms::TextBox());
			   this->text31Box = (gcnew System::Windows::Forms::TextBox());
			   this->text23Box = (gcnew System::Windows::Forms::TextBox());
			   this->text22Box = (gcnew System::Windows::Forms::TextBox());
			   this->text21Box = (gcnew System::Windows::Forms::TextBox());
			   this->text13Box = (gcnew System::Windows::Forms::TextBox());
			   this->text12Box = (gcnew System::Windows::Forms::TextBox());
			   this->text11Box = (gcnew System::Windows::Forms::TextBox());
			   this->ResultPanel = (gcnew System::Windows::Forms::Panel());
			   this->detLabel = (gcnew System::Windows::Forms::Label());
			   this->labelResult = (gcnew System::Windows::Forms::Label());
			   this->textR33Box = (gcnew System::Windows::Forms::TextBox());
			   this->textR32Box = (gcnew System::Windows::Forms::TextBox());
			   this->textR31Box = (gcnew System::Windows::Forms::TextBox());
			   this->textR23Box = (gcnew System::Windows::Forms::TextBox());
			   this->textR22Box = (gcnew System::Windows::Forms::TextBox());
			   this->textR21Box = (gcnew System::Windows::Forms::TextBox());
			   this->textR13Box = (gcnew System::Windows::Forms::TextBox());
			   this->textR12Box = (gcnew System::Windows::Forms::TextBox());
			   this->textR11Box = (gcnew System::Windows::Forms::TextBox());
			   this->SymbolPanel = (gcnew System::Windows::Forms::Panel());
			   this->buttonDot = (gcnew System::Windows::Forms::Button());
			   this->buttonDelete = (gcnew System::Windows::Forms::Button());
			   this->buttonMinus = (gcnew System::Windows::Forms::Button());
			   this->button0 = (gcnew System::Windows::Forms::Button());
			   this->button9 = (gcnew System::Windows::Forms::Button());
			   this->button8 = (gcnew System::Windows::Forms::Button());
			   this->button7 = (gcnew System::Windows::Forms::Button());
			   this->button6 = (gcnew System::Windows::Forms::Button());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->ModePanel->SuspendLayout();
			   this->FunctionPanel->SuspendLayout();
			   this->MatrixPanel->SuspendLayout();
			   this->ResultPanel->SuspendLayout();
			   this->SymbolPanel->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // ModePanel
			   // 
			   this->ModePanel->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->ModePanel->Controls->Add(this->twoMatrixMode);
			   this->ModePanel->Controls->Add(this->oneMatrixMode);
			   this->ModePanel->Controls->Add(this->modeLabel);
			   this->ModePanel->Location = System::Drawing::Point(12, 12);
			   this->ModePanel->Name = L"ModePanel";
			   this->ModePanel->Size = System::Drawing::Size(306, 255);
			   this->ModePanel->TabIndex = 0;
			   // 
			   // twoMatrixMode
			   // 
			   this->twoMatrixMode->AutoSize = true;
			   this->twoMatrixMode->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->twoMatrixMode->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->twoMatrixMode->ForeColor = System::Drawing::Color::MidnightBlue;
			   this->twoMatrixMode->Location = System::Drawing::Point(29, 175);
			   this->twoMatrixMode->Name = L"twoMatrixMode";
			   this->twoMatrixMode->Size = System::Drawing::Size(159, 27);
			   this->twoMatrixMode->TabIndex = 2;
			   this->twoMatrixMode->TabStop = true;
			   this->twoMatrixMode->Text = L"Две матрицы";
			   this->twoMatrixMode->UseVisualStyleBackColor = true;
			   this->twoMatrixMode->CheckedChanged += gcnew System::EventHandler(this, &MatrixCalculator::twoMatrixMode_CheckedChanged);
			   // 
			   // oneMatrixMode
			   // 
			   this->oneMatrixMode->AutoSize = true;
			   this->oneMatrixMode->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->oneMatrixMode->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->oneMatrixMode->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->oneMatrixMode->ForeColor = System::Drawing::Color::MidnightBlue;
			   this->oneMatrixMode->Location = System::Drawing::Point(29, 131);
			   this->oneMatrixMode->Name = L"oneMatrixMode";
			   this->oneMatrixMode->Size = System::Drawing::Size(166, 27);
			   this->oneMatrixMode->TabIndex = 1;
			   this->oneMatrixMode->TabStop = true;
			   this->oneMatrixMode->Text = L"Одна матрица";
			   this->oneMatrixMode->UseVisualStyleBackColor = false;
			   this->oneMatrixMode->CheckedChanged += gcnew System::EventHandler(this, &MatrixCalculator::oneMatrixMode_CheckedChanged);
			   // 
			   // modeLabel
			   // 
			   this->modeLabel->AutoSize = true;
			   this->modeLabel->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->modeLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->modeLabel->Location = System::Drawing::Point(62, 45);
			   this->modeLabel->Name = L"modeLabel";
			   this->modeLabel->Size = System::Drawing::Size(157, 39);
			   this->modeLabel->TabIndex = 0;
			   this->modeLabel->Text = L"РЕЖИМ:";
			   // 
			   // FunctionPanel
			   // 
			   this->FunctionPanel->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->FunctionPanel->Controls->Add(this->transposeButton);
			   this->FunctionPanel->Controls->Add(this->inverseButton);
			   this->FunctionPanel->Controls->Add(this->findDetButton);
			   this->FunctionPanel->Controls->Add(this->comboBox2);
			   this->FunctionPanel->Controls->Add(this->comboBox1);
			   this->FunctionPanel->Controls->Add(this->dimLabel2);
			   this->FunctionPanel->Controls->Add(this->dimLabel1);
			   this->FunctionPanel->Location = System::Drawing::Point(324, 12);
			   this->FunctionPanel->Name = L"FunctionPanel";
			   this->FunctionPanel->Size = System::Drawing::Size(928, 158);
			   this->FunctionPanel->TabIndex = 1;
			   // 
			   // transposeButton
			   // 
			   this->transposeButton->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->transposeButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->transposeButton->Location = System::Drawing::Point(638, 64);
			   this->transposeButton->Name = L"transposeButton";
			   this->transposeButton->Size = System::Drawing::Size(236, 31);
			   this->transposeButton->TabIndex = 6;
			   this->transposeButton->Text = L"Транспонировать";
			   this->transposeButton->UseVisualStyleBackColor = true;
			   this->transposeButton->Click += gcnew System::EventHandler(this, &MatrixCalculator::transposeMatrixClick);
			   // 
			   // inverseButton
			   // 
			   this->inverseButton->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->inverseButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->inverseButton->Location = System::Drawing::Point(638, 101);
			   this->inverseButton->Name = L"inverseButton";
			   this->inverseButton->Size = System::Drawing::Size(236, 31);
			   this->inverseButton->TabIndex = 5;
			   this->inverseButton->Text = L"Обратная матрица";
			   this->inverseButton->UseVisualStyleBackColor = true;
			   this->inverseButton->Click += gcnew System::EventHandler(this, &MatrixCalculator::inverseMatrixClick);
			   // 
			   // findDetButton
			   // 
			   this->findDetButton->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->findDetButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->findDetButton->Location = System::Drawing::Point(638, 26);
			   this->findDetButton->Name = L"findDetButton";
			   this->findDetButton->Size = System::Drawing::Size(236, 31);
			   this->findDetButton->TabIndex = 4;
			   this->findDetButton->Text = L"Найти определитель";
			   this->findDetButton->UseVisualStyleBackColor = true;
			   this->findDetButton->Click += gcnew System::EventHandler(this, &MatrixCalculator::findDetButtonClick);
			   // 
			   // comboBox2
			   // 
			   this->comboBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->comboBox2->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->comboBox2->FormattingEnabled = true;
			   this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				   L"1x1", L"1x2", L"1x3", L"2x1", L"2x2", L"2x3",
					   L"3x1", L"3x2", L"3x3"
			   });
			   this->comboBox2->Location = System::Drawing::Point(460, 92);
			   this->comboBox2->Name = L"comboBox2";
			   this->comboBox2->Size = System::Drawing::Size(121, 31);
			   this->comboBox2->TabIndex = 3;
			   this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MatrixCalculator::comboBox2_SelectedIndexChanged);
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->comboBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				   L"1x1", L"1x2", L"1x3", L"2x1", L"2x2", L"2x3",
					   L"3x1", L"3x2", L"3x3"
			   });
			   this->comboBox1->Location = System::Drawing::Point(460, 34);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(121, 31);
			   this->comboBox1->TabIndex = 2;
			   this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MatrixCalculator::comboBox1_SelectedIndexChanged);
			   // 
			   // dimLabel2
			   // 
			   this->dimLabel2->AutoSize = true;
			   this->dimLabel2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->dimLabel2->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->dimLabel2->Location = System::Drawing::Point(15, 84);
			   this->dimLabel2->Name = L"dimLabel2";
			   this->dimLabel2->Size = System::Drawing::Size(429, 39);
			   this->dimLabel2->TabIndex = 1;
			   this->dimLabel2->Text = L"Размерность матрицы 2:";
			   // 
			   // dimLabel1
			   // 
			   this->dimLabel1->AutoSize = true;
			   this->dimLabel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->dimLabel1->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->dimLabel1->Location = System::Drawing::Point(15, 26);
			   this->dimLabel1->Name = L"dimLabel1";
			   this->dimLabel1->Size = System::Drawing::Size(429, 39);
			   this->dimLabel1->TabIndex = 0;
			   this->dimLabel1->Text = L"Размерность матрицы 1:";
			   // 
			   // MatrixPanel
			   // 
			   this->MatrixPanel->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->MatrixPanel->Controls->Add(this->fieldsLabel);
			   this->MatrixPanel->Controls->Add(this->warningLabel);
			   this->MatrixPanel->Controls->Add(this->comboBoxOperator);
			   this->MatrixPanel->Controls->Add(this->findButton);
			   this->MatrixPanel->Controls->Add(this->label2);
			   this->MatrixPanel->Controls->Add(this->label1);
			   this->MatrixPanel->Controls->Add(this->text233Box);
			   this->MatrixPanel->Controls->Add(this->text232Box);
			   this->MatrixPanel->Controls->Add(this->text231Box);
			   this->MatrixPanel->Controls->Add(this->text223Box);
			   this->MatrixPanel->Controls->Add(this->text222Box);
			   this->MatrixPanel->Controls->Add(this->text221Box);
			   this->MatrixPanel->Controls->Add(this->text213Box);
			   this->MatrixPanel->Controls->Add(this->text212Box);
			   this->MatrixPanel->Controls->Add(this->text211Box);
			   this->MatrixPanel->Controls->Add(this->text33Box);
			   this->MatrixPanel->Controls->Add(this->text32Box);
			   this->MatrixPanel->Controls->Add(this->text31Box);
			   this->MatrixPanel->Controls->Add(this->text23Box);
			   this->MatrixPanel->Controls->Add(this->text22Box);
			   this->MatrixPanel->Controls->Add(this->text21Box);
			   this->MatrixPanel->Controls->Add(this->text13Box);
			   this->MatrixPanel->Controls->Add(this->text12Box);
			   this->MatrixPanel->Controls->Add(this->text11Box);
			   this->MatrixPanel->Location = System::Drawing::Point(324, 176);
			   this->MatrixPanel->Name = L"MatrixPanel";
			   this->MatrixPanel->Size = System::Drawing::Size(612, 493);
			   this->MatrixPanel->TabIndex = 2;
			   // 
			   // fieldsLabel
			   // 
			   this->fieldsLabel->AutoSize = true;
			   this->fieldsLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->fieldsLabel->ForeColor = System::Drawing::Color::MidnightBlue;
			   this->fieldsLabel->Location = System::Drawing::Point(248, 11);
			   this->fieldsLabel->Name = L"fieldsLabel";
			   this->fieldsLabel->Size = System::Drawing::Size(125, 23);
			   this->fieldsLabel->TabIndex = 23;
			   this->fieldsLabel->Text = L"Поле ввода";
			   // 
			   // warningLabel
			   // 
			   this->warningLabel->AutoSize = true;
			   this->warningLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->warningLabel->Location = System::Drawing::Point(18, 439);
			   this->warningLabel->Name = L"warningLabel";
			   this->warningLabel->Size = System::Drawing::Size(580, 38);
			   this->warningLabel->TabIndex = 22;
			   this->warningLabel->Text = L"ПРЕДУПРЕЖДЕНИЕ: некорректные значения введенных элементов\nбудут заменены на число"
				   L" 0.";
			   // 
			   // comboBoxOperator
			   // 
			   this->comboBoxOperator->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->comboBoxOperator->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->comboBoxOperator->FormattingEnabled = true;
			   this->comboBoxOperator->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"+", L"-", L"*" });
			   this->comboBoxOperator->Location = System::Drawing::Point(283, 141);
			   this->comboBoxOperator->Name = L"comboBoxOperator";
			   this->comboBoxOperator->Size = System::Drawing::Size(50, 31);
			   this->comboBoxOperator->TabIndex = 7;
			   // 
			   // findButton
			   // 
			   this->findButton->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->findButton->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->findButton->Location = System::Drawing::Point(216, 276);
			   this->findButton->Name = L"findButton";
			   this->findButton->Size = System::Drawing::Size(185, 36);
			   this->findButton->TabIndex = 21;
			   this->findButton->Text = L"Найти";
			   this->findButton->UseVisualStyleBackColor = true;
			   this->findButton->Click += gcnew System::EventHandler(this, &MatrixCalculator::findButtonClick);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->ForeColor = System::Drawing::Color::MidnightBlue;
			   this->label2->Location = System::Drawing::Point(346, 50);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(27, 23);
			   this->label2->TabIndex = 20;
			   this->label2->Text = L"2)";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->ForeColor = System::Drawing::Color::MidnightBlue;
			   this->label1->Location = System::Drawing::Point(37, 50);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(27, 23);
			   this->label1->TabIndex = 19;
			   this->label1->Text = L"1)";
			   // 
			   // text233Box
			   // 
			   this->text233Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text233Box->Location = System::Drawing::Point(504, 180);
			   this->text233Box->Name = L"text233Box";
			   this->text233Box->Size = System::Drawing::Size(71, 40);
			   this->text233Box->TabIndex = 17;
			   this->text233Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text232Box
			   // 
			   this->text232Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text232Box->Location = System::Drawing::Point(427, 180);
			   this->text232Box->Name = L"text232Box";
			   this->text232Box->Size = System::Drawing::Size(71, 40);
			   this->text232Box->TabIndex = 16;
			   this->text232Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text231Box
			   // 
			   this->text231Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text231Box->Location = System::Drawing::Point(350, 180);
			   this->text231Box->Name = L"text231Box";
			   this->text231Box->Size = System::Drawing::Size(71, 40);
			   this->text231Box->TabIndex = 15;
			   this->text231Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text223Box
			   // 
			   this->text223Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text223Box->Location = System::Drawing::Point(504, 133);
			   this->text223Box->Name = L"text223Box";
			   this->text223Box->Size = System::Drawing::Size(71, 40);
			   this->text223Box->TabIndex = 14;
			   this->text223Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text222Box
			   // 
			   this->text222Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text222Box->Location = System::Drawing::Point(427, 134);
			   this->text222Box->Name = L"text222Box";
			   this->text222Box->Size = System::Drawing::Size(71, 40);
			   this->text222Box->TabIndex = 13;
			   this->text222Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text221Box
			   // 
			   this->text221Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text221Box->Location = System::Drawing::Point(350, 134);
			   this->text221Box->Name = L"text221Box";
			   this->text221Box->Size = System::Drawing::Size(71, 40);
			   this->text221Box->TabIndex = 12;
			   this->text221Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text213Box
			   // 
			   this->text213Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text213Box->Location = System::Drawing::Point(504, 87);
			   this->text213Box->Name = L"text213Box";
			   this->text213Box->Size = System::Drawing::Size(71, 40);
			   this->text213Box->TabIndex = 11;
			   this->text213Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text212Box
			   // 
			   this->text212Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text212Box->Location = System::Drawing::Point(427, 87);
			   this->text212Box->Name = L"text212Box";
			   this->text212Box->Size = System::Drawing::Size(71, 40);
			   this->text212Box->TabIndex = 10;
			   this->text212Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text211Box
			   // 
			   this->text211Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text211Box->Location = System::Drawing::Point(350, 87);
			   this->text211Box->Name = L"text211Box";
			   this->text211Box->Size = System::Drawing::Size(71, 40);
			   this->text211Box->TabIndex = 9;
			   this->text211Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text33Box
			   // 
			   this->text33Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text33Box->Location = System::Drawing::Point(195, 179);
			   this->text33Box->Name = L"text33Box";
			   this->text33Box->Size = System::Drawing::Size(71, 40);
			   this->text33Box->TabIndex = 8;
			   this->text33Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text32Box
			   // 
			   this->text32Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text32Box->Location = System::Drawing::Point(118, 179);
			   this->text32Box->Name = L"text32Box";
			   this->text32Box->Size = System::Drawing::Size(71, 40);
			   this->text32Box->TabIndex = 7;
			   this->text32Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text31Box
			   // 
			   this->text31Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text31Box->Location = System::Drawing::Point(41, 179);
			   this->text31Box->Name = L"text31Box";
			   this->text31Box->Size = System::Drawing::Size(71, 40);
			   this->text31Box->TabIndex = 6;
			   this->text31Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text23Box
			   // 
			   this->text23Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text23Box->Location = System::Drawing::Point(195, 133);
			   this->text23Box->Name = L"text23Box";
			   this->text23Box->Size = System::Drawing::Size(71, 40);
			   this->text23Box->TabIndex = 5;
			   this->text23Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text22Box
			   // 
			   this->text22Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text22Box->Location = System::Drawing::Point(118, 133);
			   this->text22Box->Name = L"text22Box";
			   this->text22Box->Size = System::Drawing::Size(71, 40);
			   this->text22Box->TabIndex = 4;
			   this->text22Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text21Box
			   // 
			   this->text21Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text21Box->Location = System::Drawing::Point(41, 133);
			   this->text21Box->Name = L"text21Box";
			   this->text21Box->Size = System::Drawing::Size(71, 40);
			   this->text21Box->TabIndex = 3;
			   this->text21Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text13Box
			   // 
			   this->text13Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text13Box->Location = System::Drawing::Point(195, 87);
			   this->text13Box->Name = L"text13Box";
			   this->text13Box->Size = System::Drawing::Size(71, 40);
			   this->text13Box->TabIndex = 2;
			   this->text13Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text12Box
			   // 
			   this->text12Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text12Box->Location = System::Drawing::Point(118, 87);
			   this->text12Box->Name = L"text12Box";
			   this->text12Box->Size = System::Drawing::Size(71, 40);
			   this->text12Box->TabIndex = 1;
			   this->text12Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // text11Box
			   // 
			   this->text11Box->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->text11Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->text11Box->Location = System::Drawing::Point(41, 87);
			   this->text11Box->Name = L"text11Box";
			   this->text11Box->Size = System::Drawing::Size(71, 40);
			   this->text11Box->TabIndex = 0;
			   this->text11Box->Enter += gcnew System::EventHandler(this, &MatrixCalculator::TextBoxEnter);
			   // 
			   // ResultPanel
			   // 
			   this->ResultPanel->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->ResultPanel->Controls->Add(this->detLabel);
			   this->ResultPanel->Controls->Add(this->labelResult);
			   this->ResultPanel->Controls->Add(this->textR33Box);
			   this->ResultPanel->Controls->Add(this->textR32Box);
			   this->ResultPanel->Controls->Add(this->textR31Box);
			   this->ResultPanel->Controls->Add(this->textR23Box);
			   this->ResultPanel->Controls->Add(this->textR22Box);
			   this->ResultPanel->Controls->Add(this->textR21Box);
			   this->ResultPanel->Controls->Add(this->textR13Box);
			   this->ResultPanel->Controls->Add(this->textR12Box);
			   this->ResultPanel->Controls->Add(this->textR11Box);
			   this->ResultPanel->Location = System::Drawing::Point(942, 176);
			   this->ResultPanel->Name = L"ResultPanel";
			   this->ResultPanel->Size = System::Drawing::Size(310, 493);
			   this->ResultPanel->TabIndex = 3;
			   // 
			   // detLabel
			   // 
			   this->detLabel->AutoSize = true;
			   this->detLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->detLabel->Location = System::Drawing::Point(38, 87);
			   this->detLabel->Name = L"detLabel";
			   this->detLabel->Size = System::Drawing::Size(0, 23);
			   this->detLabel->TabIndex = 28;
			   // 
			   // labelResult
			   // 
			   this->labelResult->AutoSize = true;
			   this->labelResult->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->labelResult->ForeColor = System::Drawing::Color::MidnightBlue;
			   this->labelResult->Location = System::Drawing::Point(106, 11);
			   this->labelResult->Name = L"labelResult";
			   this->labelResult->Size = System::Drawing::Size(108, 23);
			   this->labelResult->TabIndex = 27;
			   this->labelResult->Text = L"Результат";
			   // 
			   // textR33Box
			   // 
			   this->textR33Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textR33Box->Location = System::Drawing::Point(207, 180);
			   this->textR33Box->Name = L"textR33Box";
			   this->textR33Box->Size = System::Drawing::Size(71, 40);
			   this->textR33Box->TabIndex = 26;
			   // 
			   // textR32Box
			   // 
			   this->textR32Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textR32Box->Location = System::Drawing::Point(130, 180);
			   this->textR32Box->Name = L"textR32Box";
			   this->textR32Box->Size = System::Drawing::Size(71, 40);
			   this->textR32Box->TabIndex = 25;
			   // 
			   // textR31Box
			   // 
			   this->textR31Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textR31Box->Location = System::Drawing::Point(53, 180);
			   this->textR31Box->Name = L"textR31Box";
			   this->textR31Box->Size = System::Drawing::Size(71, 40);
			   this->textR31Box->TabIndex = 24;
			   // 
			   // textR23Box
			   // 
			   this->textR23Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textR23Box->Location = System::Drawing::Point(207, 133);
			   this->textR23Box->Name = L"textR23Box";
			   this->textR23Box->Size = System::Drawing::Size(71, 40);
			   this->textR23Box->TabIndex = 23;
			   // 
			   // textR22Box
			   // 
			   this->textR22Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textR22Box->Location = System::Drawing::Point(130, 134);
			   this->textR22Box->Name = L"textR22Box";
			   this->textR22Box->Size = System::Drawing::Size(71, 40);
			   this->textR22Box->TabIndex = 22;
			   // 
			   // textR21Box
			   // 
			   this->textR21Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textR21Box->Location = System::Drawing::Point(53, 134);
			   this->textR21Box->Name = L"textR21Box";
			   this->textR21Box->Size = System::Drawing::Size(71, 40);
			   this->textR21Box->TabIndex = 21;
			   // 
			   // textR13Box
			   // 
			   this->textR13Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textR13Box->Location = System::Drawing::Point(207, 87);
			   this->textR13Box->Name = L"textR13Box";
			   this->textR13Box->Size = System::Drawing::Size(71, 40);
			   this->textR13Box->TabIndex = 20;
			   // 
			   // textR12Box
			   // 
			   this->textR12Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textR12Box->Location = System::Drawing::Point(130, 87);
			   this->textR12Box->Name = L"textR12Box";
			   this->textR12Box->Size = System::Drawing::Size(71, 40);
			   this->textR12Box->TabIndex = 19;
			   // 
			   // textR11Box
			   // 
			   this->textR11Box->BackColor = System::Drawing::SystemColors::MenuBar;
			   this->textR11Box->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->textR11Box->Location = System::Drawing::Point(54, 87);
			   this->textR11Box->Name = L"textR11Box";
			   this->textR11Box->ReadOnly = true;
			   this->textR11Box->Size = System::Drawing::Size(71, 40);
			   this->textR11Box->TabIndex = 18;
			   // 
			   // SymbolPanel
			   // 
			   this->SymbolPanel->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->SymbolPanel->Controls->Add(this->buttonDot);
			   this->SymbolPanel->Controls->Add(this->buttonDelete);
			   this->SymbolPanel->Controls->Add(this->buttonMinus);
			   this->SymbolPanel->Controls->Add(this->button0);
			   this->SymbolPanel->Controls->Add(this->button9);
			   this->SymbolPanel->Controls->Add(this->button8);
			   this->SymbolPanel->Controls->Add(this->button7);
			   this->SymbolPanel->Controls->Add(this->button6);
			   this->SymbolPanel->Controls->Add(this->button5);
			   this->SymbolPanel->Controls->Add(this->button4);
			   this->SymbolPanel->Controls->Add(this->button3);
			   this->SymbolPanel->Controls->Add(this->button2);
			   this->SymbolPanel->Controls->Add(this->button1);
			   this->SymbolPanel->Location = System::Drawing::Point(12, 273);
			   this->SymbolPanel->Name = L"SymbolPanel";
			   this->SymbolPanel->Size = System::Drawing::Size(306, 396);
			   this->SymbolPanel->TabIndex = 4;
			   // 
			   // buttonDot
			   // 
			   this->buttonDot->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->buttonDot->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->buttonDot->Location = System::Drawing::Point(110, 307);
			   this->buttonDot->Name = L"buttonDot";
			   this->buttonDot->Size = System::Drawing::Size(90, 70);
			   this->buttonDot->TabIndex = 15;
			   this->buttonDot->Text = L",";
			   this->buttonDot->UseVisualStyleBackColor = true;
			   this->buttonDot->Click += gcnew System::EventHandler(this, &MatrixCalculator::ButtonClick);
			   // 
			   // buttonDelete
			   // 
			   this->buttonDelete->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->buttonDelete->Location = System::Drawing::Point(206, 307);
			   this->buttonDelete->Name = L"buttonDelete";
			   this->buttonDelete->Size = System::Drawing::Size(90, 70);
			   this->buttonDelete->TabIndex = 14;
			   this->buttonDelete->Text = L"del";
			   this->buttonDelete->UseVisualStyleBackColor = true;
			   this->buttonDelete->Click += gcnew System::EventHandler(this, &MatrixCalculator::ButtonClick);
			   // 
			   // buttonMinus
			   // 
			   this->buttonMinus->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->buttonMinus->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->buttonMinus->Location = System::Drawing::Point(14, 307);
			   this->buttonMinus->Name = L"buttonMinus";
			   this->buttonMinus->Size = System::Drawing::Size(90, 70);
			   this->buttonMinus->TabIndex = 13;
			   this->buttonMinus->Text = L"-";
			   this->buttonMinus->UseVisualStyleBackColor = true;
			   this->buttonMinus->Click += gcnew System::EventHandler(this, &MatrixCalculator::ButtonClick);
			   // 
			   // button0
			   // 
			   this->button0->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->button0->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button0->Location = System::Drawing::Point(110, 231);
			   this->button0->Name = L"button0";
			   this->button0->Size = System::Drawing::Size(90, 70);
			   this->button0->TabIndex = 9;
			   this->button0->Text = L"0";
			   this->button0->UseVisualStyleBackColor = true;
			   this->button0->Click += gcnew System::EventHandler(this, &MatrixCalculator::ButtonClick);
			   // 
			   // button9
			   // 
			   this->button9->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->button9->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button9->Location = System::Drawing::Point(206, 155);
			   this->button9->Name = L"button9";
			   this->button9->Size = System::Drawing::Size(90, 70);
			   this->button9->TabIndex = 8;
			   this->button9->Text = L"9";
			   this->button9->UseVisualStyleBackColor = true;
			   this->button9->Click += gcnew System::EventHandler(this, &MatrixCalculator::ButtonClick);
			   // 
			   // button8
			   // 
			   this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->button8->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button8->Location = System::Drawing::Point(110, 155);
			   this->button8->Name = L"button8";
			   this->button8->Size = System::Drawing::Size(90, 70);
			   this->button8->TabIndex = 7;
			   this->button8->Text = L"8";
			   this->button8->UseVisualStyleBackColor = true;
			   this->button8->Click += gcnew System::EventHandler(this, &MatrixCalculator::ButtonClick);
			   // 
			   // button7
			   // 
			   this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->button7->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button7->Location = System::Drawing::Point(14, 155);
			   this->button7->Name = L"button7";
			   this->button7->Size = System::Drawing::Size(90, 70);
			   this->button7->TabIndex = 6;
			   this->button7->Text = L"7";
			   this->button7->UseVisualStyleBackColor = true;
			   this->button7->Click += gcnew System::EventHandler(this, &MatrixCalculator::ButtonClick);
			   // 
			   // button6
			   // 
			   this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->button6->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button6->Location = System::Drawing::Point(206, 83);
			   this->button6->Name = L"button6";
			   this->button6->Size = System::Drawing::Size(90, 70);
			   this->button6->TabIndex = 5;
			   this->button6->Text = L"6";
			   this->button6->UseVisualStyleBackColor = true;
			   this->button6->Click += gcnew System::EventHandler(this, &MatrixCalculator::ButtonClick);
			   // 
			   // button5
			   // 
			   this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->button5->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button5->Location = System::Drawing::Point(110, 83);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(90, 70);
			   this->button5->TabIndex = 4;
			   this->button5->Text = L"5";
			   this->button5->UseVisualStyleBackColor = true;
			   this->button5->Click += gcnew System::EventHandler(this, &MatrixCalculator::ButtonClick);
			   // 
			   // button4
			   // 
			   this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->button4->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button4->Location = System::Drawing::Point(14, 83);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(90, 70);
			   this->button4->TabIndex = 3;
			   this->button4->Text = L"4";
			   this->button4->UseVisualStyleBackColor = true;
			   this->button4->Click += gcnew System::EventHandler(this, &MatrixCalculator::ButtonClick);
			   // 
			   // button3
			   // 
			   this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->button3->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button3->Location = System::Drawing::Point(206, 11);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(90, 70);
			   this->button3->TabIndex = 2;
			   this->button3->Text = L"3";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &MatrixCalculator::ButtonClick);
			   // 
			   // button2
			   // 
			   this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->button2->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button2->Location = System::Drawing::Point(110, 11);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(90, 70);
			   this->button2->TabIndex = 1;
			   this->button2->Text = L"2";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &MatrixCalculator::ButtonClick);
			   // 
			   // button1
			   // 
			   this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button1->Location = System::Drawing::Point(14, 11);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(90, 70);
			   this->button1->TabIndex = 0;
			   this->button1->Text = L"1";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MatrixCalculator::ButtonClick);
			   // 
			   // MatrixCalculator
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 14);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->ClientSize = System::Drawing::Size(1264, 681);
			   this->Controls->Add(this->SymbolPanel);
			   this->Controls->Add(this->ResultPanel);
			   this->Controls->Add(this->MatrixPanel);
			   this->Controls->Add(this->FunctionPanel);
			   this->Controls->Add(this->ModePanel);
			   this->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 8.249999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ForeColor = System::Drawing::Color::CornflowerBlue;
			   this->Location = System::Drawing::Point(177, 220);
			   this->MaximumSize = System::Drawing::Size(1280, 720);
			   this->MinimumSize = System::Drawing::Size(1280, 720);
			   this->Name = L"MatrixCalculator";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Matrix Calculator";
			   this->Load += gcnew System::EventHandler(this, &MatrixCalculator::MatrixCalculator_Load);
			   this->ModePanel->ResumeLayout(false);
			   this->ModePanel->PerformLayout();
			   this->FunctionPanel->ResumeLayout(false);
			   this->FunctionPanel->PerformLayout();
			   this->MatrixPanel->ResumeLayout(false);
			   this->MatrixPanel->PerformLayout();
			   this->ResultPanel->ResumeLayout(false);
			   this->ResultPanel->PerformLayout();
			   this->SymbolPanel->ResumeLayout(false);
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private: System::Void MatrixCalculator_Load(System::Object^ sender, System::EventArgs^ e) {
		this->comboBox1->SelectedIndex = 8;
		this->comboBox2->SelectedIndex = 8;
		this->comboBoxOperator->SelectedIndex = 0;
		this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBoxOperator->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->textR11Box->ReadOnly = true;
		this->textR12Box->ReadOnly = true;
		this->textR13Box->ReadOnly = true;
		this->textR21Box->ReadOnly = true;
		this->textR22Box->ReadOnly = true;
		this->textR23Box->ReadOnly = true;
		this->textR31Box->ReadOnly = true;
		this->textR32Box->ReadOnly = true;
		this->textR33Box->ReadOnly = true;
	}

		   System::Void oneMatrixMode_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			   dimLabel2->Hide();
			   label2->Hide();
			   comboBox2->Hide();
			   transposeButton->Show();
			   inverseButton->Show();
			   findDetButton->Show();
			   findButton->Hide();
			   comboBoxOperator->Hide();
			   text211Box->Hide();
			   text212Box->Hide();
			   text213Box->Hide();
			   text221Box->Hide();
			   text222Box->Hide();
			   text223Box->Hide();
			   text231Box->Hide();
			   text232Box->Hide();
			   text233Box->Hide();
			   textR11Box->Hide();
			   textR12Box->Hide();
			   textR13Box->Hide();
			   textR21Box->Hide();
			   textR22Box->Hide();
			   textR23Box->Hide();
			   textR31Box->Hide();
			   textR32Box->Hide();
			   textR33Box->Hide();
		   }
		   System::Void twoMatrixMode_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			   detLabel->Hide();
			   dimLabel2->Show();
			   label2->Show();
			   comboBox2->Show();
			   transposeButton->Hide();
			   inverseButton->Hide();
			   findDetButton->Hide();
			   findButton->Show();
			   comboBoxOperator->Show();
			   text211Box->Show();
			   text212Box->Show();
			   text213Box->Show();
			   text221Box->Show();
			   text222Box->Show();
			   text223Box->Show();
			   text231Box->Show();
			   text232Box->Show();
			   text233Box->Show();
			   textR11Box->Show();
			   textR12Box->Show();
			   textR13Box->Show();
			   textR21Box->Show();
			   textR22Box->Show();
			   textR23Box->Show();
			   textR31Box->Show();
			   textR32Box->Show();
			   textR33Box->Show();
			   textR11Box->Text = "";
			   textR12Box->Text = "";
			   textR13Box->Text = "";
			   textR21Box->Text = "";
			   textR22Box->Text = "";
			   textR23Box->Text = "";
			   textR31Box->Text = "";
			   textR32Box->Text = "";
			   textR33Box->Text = "";
		   }

		   System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			   if (this->comboBox1->SelectedIndex == 0) {
				   text12Box->Hide();
				   text13Box->Hide();
				   text21Box->Hide();
				   text22Box->Hide();
				   text23Box->Hide();
				   text31Box->Hide();
				   text32Box->Hide();
				   text33Box->Hide();
				   rows1M = 1;
				   columns1M = 1;
			   }
			   if (this->comboBox1->SelectedIndex == 1) {
				   text12Box->Show();
				   text13Box->Hide();
				   text21Box->Hide();
				   text22Box->Hide();
				   text23Box->Hide();
				   text31Box->Hide();
				   text32Box->Hide();
				   text33Box->Hide();
				   rows1M = 1;
				   columns1M = 2;
			   }
			   if (this->comboBox1->SelectedIndex == 2) {
				   text12Box->Show();
				   text13Box->Show();
				   text21Box->Hide();
				   text22Box->Hide();
				   text23Box->Hide();
				   text31Box->Hide();
				   text32Box->Hide();
				   text33Box->Hide();
				   rows1M = 1;
				   columns1M = 3;
			   }
			   if (this->comboBox1->SelectedIndex == 3) {
				   text12Box->Hide();
				   text13Box->Hide();
				   text21Box->Show();
				   text22Box->Hide();
				   text23Box->Hide();
				   text31Box->Hide();
				   text32Box->Hide();
				   text33Box->Hide();
				   rows1M = 2;
				   columns1M = 1;
			   }
			   if (this->comboBox1->SelectedIndex == 4) {
				   text12Box->Show();
				   text13Box->Hide();
				   text21Box->Show();
				   text22Box->Show();
				   text23Box->Hide();
				   text31Box->Hide();
				   text32Box->Hide();
				   text33Box->Hide();
				   rows1M = 2;
				   columns1M = 2;
			   }
			   if (this->comboBox1->SelectedIndex == 5) {
				   text12Box->Show();
				   text13Box->Show();
				   text21Box->Show();
				   text22Box->Show();
				   text23Box->Show();
				   text31Box->Hide();
				   text32Box->Hide();
				   text33Box->Hide();
				   rows1M = 2;
				   columns1M = 3;
			   }
			   if (this->comboBox1->SelectedIndex == 6) {
				   text12Box->Hide();
				   text13Box->Hide();
				   text21Box->Show();
				   text22Box->Hide();
				   text23Box->Hide();
				   text31Box->Show();
				   text32Box->Hide();
				   text33Box->Hide();
				   rows1M = 3;
				   columns1M = 1;
			   }
			   if (this->comboBox1->SelectedIndex == 7) {
				   text12Box->Show();
				   text13Box->Hide();
				   text21Box->Show();
				   text22Box->Show();
				   text23Box->Hide();
				   text31Box->Show();
				   text32Box->Show();
				   text33Box->Hide();
				   rows1M = 3;
				   columns1M = 2;
			   }
			   if (this->comboBox1->SelectedIndex == 8) {
				   text12Box->Show();
				   text13Box->Show();
				   text21Box->Show();
				   text22Box->Show();
				   text23Box->Show();
				   text31Box->Show();
				   text32Box->Show();
				   text33Box->Show();
				   rows1M = 3;
				   columns1M = 3;
			   }

		   }
		   System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			   if (this->comboBox2->SelectedIndex == 0) {
				   text212Box->Hide();
				   text213Box->Hide();
				   text221Box->Hide();
				   text222Box->Hide();
				   text223Box->Hide();
				   text231Box->Hide();
				   text232Box->Hide();
				   text233Box->Hide();
				   rows2M = 1;
				   columns2M = 1;
			   }
			   if (this->comboBox2->SelectedIndex == 1) {
				   text212Box->Show();
				   text213Box->Hide();
				   text221Box->Hide();
				   text222Box->Hide();
				   text223Box->Hide();
				   text231Box->Hide();
				   text232Box->Hide();
				   text233Box->Hide();
				   rows2M = 1;
				   columns2M = 2;
			   }
			   if (this->comboBox2->SelectedIndex == 2) {
				   text212Box->Show();
				   text213Box->Show();
				   text221Box->Hide();
				   text222Box->Hide();
				   text223Box->Hide();
				   text231Box->Hide();
				   text232Box->Hide();
				   text233Box->Hide();
				   rows2M = 1;
				   columns2M = 3;
			   }
			   if (this->comboBox2->SelectedIndex == 3) {
				   text212Box->Hide();
				   text213Box->Hide();
				   text221Box->Show();
				   text222Box->Hide();
				   text223Box->Hide();
				   text231Box->Hide();
				   text232Box->Hide();
				   text233Box->Hide();
				   rows2M = 2;
				   columns2M = 1;
			   }
			   if (this->comboBox2->SelectedIndex == 4) {
				   text212Box->Show();
				   text213Box->Hide();
				   text221Box->Show();
				   text222Box->Show();
				   text223Box->Hide();
				   text231Box->Hide();
				   text232Box->Hide();
				   text233Box->Hide();
				   rows2M = 2;
				   columns2M = 2;
			   }
			   if (this->comboBox2->SelectedIndex == 5) {
				   text212Box->Show();
				   text213Box->Show();
				   text221Box->Show();
				   text222Box->Show();
				   text223Box->Show();
				   text231Box->Hide();
				   text232Box->Hide();
				   text233Box->Hide();
				   rows2M = 2;
				   columns2M = 3;
			   }
			   if (this->comboBox2->SelectedIndex == 6) {
				   text212Box->Hide();
				   text213Box->Hide();
				   text221Box->Show();
				   text222Box->Hide();
				   text223Box->Hide();
				   text231Box->Show();
				   text232Box->Hide();
				   text233Box->Hide();
				   rows2M = 3;
				   columns2M = 1;
			   }
			   if (this->comboBox2->SelectedIndex == 7) {
				   text212Box->Show();
				   text213Box->Hide();
				   text221Box->Show();
				   text222Box->Show();
				   text223Box->Hide();
				   text231Box->Show();
				   text232Box->Show();
				   text233Box->Hide();
				   rows2M = 3;
				   columns2M = 2;
			   }
			   if (this->comboBox2->SelectedIndex == 8) {
				   text212Box->Show();
				   text213Box->Show();
				   text221Box->Show();
				   text222Box->Show();
				   text223Box->Show();
				   text231Box->Show();
				   text232Box->Show();
				   text233Box->Show();
				   rows2M = 3;
				   columns2M = 3;
			   }
		   }

		   TextBox^ focusedTextBox = nullptr;

		   System::Void ButtonClick(Object^ sender, EventArgs^ e)
		   {
			   if (focusedTextBox == nullptr) return;
			   Button^ button = dynamic_cast<Button^>(sender);
			   String^ value = button->Text;
			   String^ text = focusedTextBox->Text;
			   if (value == "," && text->Length == 0) return;
			   if (value == "0" && text == "0") return;
			   if (value == "del" && focusedTextBox->Text != "")
			   {
				   int selectionStart = focusedTextBox->SelectionStart;
				   int selectionLength = focusedTextBox->SelectionLength;

				   if (selectionLength > 0)
				   {
					   focusedTextBox->Text = focusedTextBox->Text->Remove(selectionStart, selectionLength);
					   focusedTextBox->SelectionStart = selectionStart;
					   focusedTextBox->SelectionLength = 0;
				   }
				   else if (selectionStart > 0)
				   {
					   focusedTextBox->Text = focusedTextBox->Text->Remove(selectionStart - 1, 1);
					   focusedTextBox->SelectionStart = selectionStart - 1;
					   focusedTextBox->SelectionLength = 0;
				   }
				   return;
			   }
			   if (value == "-") {
				   for each (char symb in text) {
					   if (symb == '-') return;
				   }
				   if (focusedTextBox->SelectionStart != 0) return;
				   int selectionStart = focusedTextBox->SelectionStart;
				   focusedTextBox->Text = focusedTextBox->Text->Insert(selectionStart, value);
				   focusedTextBox->SelectionStart = selectionStart + 1;
				   focusedTextBox->SelectionLength = 0;
			   }
			   if (value == "," && text->Length != 0) {
				   for each (char symb in text) {
					   if (symb == ',' || text[text->Length - 1] == '-' || focusedTextBox-> SelectionStart ==0) return;
				   }
				   int selectionStart = focusedTextBox->SelectionStart;
				   focusedTextBox->Text = focusedTextBox->Text->Insert(selectionStart, value);
				   focusedTextBox->SelectionStart = selectionStart + 1;
				   focusedTextBox->SelectionLength = 0;
				   return;
			   }
			   if (value == "0" || value == "1" || value == "2" || value == "3" || value == "4"
				   || value == "5" || value == "6" || value == "7" || value == "8" || value == "9") {
				   int selectionStart = focusedTextBox->SelectionStart;
				   focusedTextBox->Text = focusedTextBox->Text->Insert(selectionStart, value);
				   focusedTextBox->SelectionStart = selectionStart + 1;
				   focusedTextBox->SelectionLength = 0;
			   }
			   else return;
		   }

		   System::Void TextBoxEnter(Object^ sender, EventArgs^ e)
		   {
			   TextBox^ textBox = dynamic_cast<TextBox^>(sender);
			   focusedTextBox = textBox;
		   }

		   double** CreateMatrix1M(int rows1M, int columns1M, array<array<TextBox^>^>^ textBoxes1M) {
			   double** firstMatrix = new double* [rows1M];
			   for (int i = 0; i < rows1M; i++)
			   {
				   firstMatrix[i] = new double[columns1M];
				   for (int j = 0; j < columns1M; j++)
				   {
					   double value;
					   if (double::TryParse(textBoxes1M[i][j]->Text, value))
					   {
						   firstMatrix[i][j] = value;
					   }
					   else
					   {
						   firstMatrix[i][j] = 0; 
					   }
				   }
			   }

			   return firstMatrix;
		   }

		   double** CreateMatrix2M(int rows2M, int columns2M, array<array<TextBox^>^>^ textBoxes2M) {
			   double** secondMatrix = new double* [rows2M];
			   for (int i = 0; i < rows2M; i++)
			   {
				   secondMatrix[i] = new double[columns2M];
				   for (int j = 0; j < columns2M; j++)
				   {
					   double value;
					   if (double::TryParse(textBoxes2M[i][j]->Text, value))
					   {
						   secondMatrix[i][j] = value;
					   }
					   else
					   {
						   secondMatrix[i][j] = 0; 
					   }
				   }
			   }

			   return secondMatrix;
		   }

		   void TransposeMatrix(int rows, int columns, array<array<TextBox^>^>^ textBoxes1M, array<array<TextBox^>^>^ textBoxesRM) {
			   for (int i = 0; i < columns; i++) {
				   for (int j = 0; j < rows; j++) {
					   textBoxesRM[i][j]->Text = textBoxes1M[j][i]->Text;
					   textBoxesRM[i][j]->Visible = true;
				   }
			   }

			   for (int i = columns; i < textBoxesRM->GetLength(0); i++) {
				   for (int j = 0; j < rows; j++) {
					   textBoxesRM[i][j]->Text = "";
					   textBoxesRM[i][j]->Visible = false;
				   }
			   }
		   }
		   
		   bool IsEmptyMatrix(int rows, int columns, array<array<TextBox^>^>^ textBoxesM) {
			   bool isEmpty = false;
			   for (int i = 0; i < rows; i++) {
				   for (int j = 0; j < columns; j++) {
					   if (String::IsNullOrEmpty(textBoxesM[i][j]->Text)) {
						   isEmpty = true;
					   }
				   }
			   }
			   return isEmpty;
		   }

		   void DisplayMatrix(int rows, int columns, double** matrix, array<array<TextBox^>^>^ textBoxes) {
			   for (int i = 0; i < textBoxes->Length; i++) {
				   for (int j = 0; j < textBoxes[i]->Length; j++) {
					   if (i < rows && j < columns) {
						   textBoxes[i][j]->Text = matrix[i][j].ToString();
						   textBoxes[i][j]->Show();
					   }
					   else {
						   textBoxes[i][j]->Hide();
					   }
				   }
			   }
		   }

		   System::Void findDetButtonClick(System::Object^ sender, System::EventArgs^ e) {
			   detLabel->Show();
			   this->detLabel->Text = "Определитель\nне найден.";
			   textR11Box->Hide();
			   textR12Box->Hide();
			   textR13Box->Hide();
			   textR21Box->Hide();
			   textR22Box->Hide();
			   textR23Box->Hide();
			   textR31Box->Hide();
			   textR32Box->Hide();
			   textR33Box->Hide();
			   bool isEmpty = IsEmptyMatrix(rows1M, columns1M, textBoxes1M);
			   double** tempFirstMatrix = CreateMatrix1M(rows1M, columns1M, textBoxes1M);
			   if (isEmpty) {
				   MessageBox::Show("Не все элементы матрицы заполнены.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   return;
			   }
			   if (rows1M != columns1M) {
				   MessageBox::Show("Матрица должна быть квадратной.", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }
			   double determinant = FindDet(rows1M, columns1M, tempFirstMatrix);
			   this->detLabel->Text = "Определитель: " + determinant.ToString();
		   }

		   System::Void transposeMatrixClick(System::Object^ sender, System::EventArgs^ e) {
			   detLabel->Show();
			   this->detLabel->Text = "Транспонированная\nматрица не найдена.";
			   textR11Box->Hide();
			   textR12Box->Hide();
			   textR13Box->Hide();
			   textR21Box->Hide();
			   textR22Box->Hide();
			   textR23Box->Hide();
			   textR31Box->Hide();
			   textR32Box->Hide();
			   textR33Box->Hide();
			   int rows = rows1M;
			   int columns = columns1M;
			   bool isEmpty = IsEmptyMatrix(rows, columns, textBoxes1M);
			   if (isEmpty) {
				   MessageBox::Show("Не все элементы матрицы заполнены.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   return;
			   }
			   TransposeMatrix(rows, columns, textBoxes1M, textBoxesRM);
			   detLabel->Hide();
		   }

		   System::Void inverseMatrixClick(System::Object^ sender, System::EventArgs^ e) {
			   this->detLabel->Show();
			   this->detLabel->Text = "Обратная матрица\nне найдена.";
			   textR11Box->Hide();
			   textR12Box->Hide();
			   textR13Box->Hide();
			   textR21Box->Hide();
			   textR22Box->Hide();
			   textR23Box->Hide();
			   textR31Box->Hide();
			   textR32Box->Hide();
			   textR33Box->Hide();
			   int rows = rows1M;
			   int columns = columns1M;
			   bool isEmpty = IsEmptyMatrix(rows, columns, textBoxes1M);
			   if (rows1M != columns1M) {
				   MessageBox::Show("Матрица должна быть квадратной.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }
			   if (isEmpty) {
				   MessageBox::Show("Не все элементы матрицы заполнены.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   return;
			   }
			   double** tempFirstMatrix = CreateMatrix1M(rows, columns, textBoxes1M);
			   double determinant = FindDet(rows, columns, tempFirstMatrix);

			   if (determinant == 0) {
				   detLabel->Show();
				   this->detLabel->Text = "Обратной матрицы\nне существует, т.к.\nопределитель равен 0.";
			   }

			   else {
				   double** tempInversedMatrix = InverseMatrix(rows, columns, tempFirstMatrix, determinant);
				   DisplayMatrix(rows, columns, tempInversedMatrix, textBoxesRM);
				   detLabel->Hide();
			   }

		   }

		   System::Void findButtonClick(System::Object^ sender, System::EventArgs^ e) {
			   if (IsEmptyMatrix(rows1M, columns1M, textBoxes1M) || IsEmptyMatrix(rows2M, columns2M, textBoxes2M)) {
				   MessageBox::Show("Не все элементы матрицы заполнены.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   return;
			   }
			   else {
				   if (comboBoxOperator->SelectedIndex == 0) {
					   double** firstMatrix = CreateMatrix1M(rows1M, columns1M, textBoxes1M);
					   double** secondMatrix = CreateMatrix2M(rows2M, columns2M, textBoxes2M);
					   if (!IsMatrixJoint(rows1M, columns1M, rows2M, columns2M)) {
						   MessageBox::Show("Матрицы на совместны.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
						   return;
					   }
					   double** tempResultMatrix = SumMatrices(rows1M, columns1M, firstMatrix, secondMatrix);
					   DisplayMatrix(rows1M, columns1M, tempResultMatrix, textBoxesRM);
				   }
				   if (comboBoxOperator->SelectedIndex == 1) {
					   double** firstMatrix = CreateMatrix1M(rows1M, columns1M, textBoxes1M);
					   double** secondMatrix = CreateMatrix2M(rows2M, columns2M, textBoxes2M);
					   if (!IsMatrixJoint(rows1M, columns1M, rows2M, columns2M)) {
						   MessageBox::Show("Матрицы на совместны.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
						   return;
					   }
					   double** tempResultMatrix = SubstractMatrices(rows1M, columns1M, firstMatrix, secondMatrix);
					   DisplayMatrix(rows1M, columns1M, tempResultMatrix, textBoxesRM);
				   }
				   if (comboBoxOperator->SelectedIndex == 2) {
					   double** firstMatrix = CreateMatrix1M(rows1M, columns1M, textBoxes1M);
					   double** secondMatrix = CreateMatrix2M(rows2M, columns2M, textBoxes2M);
					   if (!IsMatrixConsistent(rows1M, columns1M, rows2M, columns2M) && comboBox1->SelectedIndex != 0) {
						   MessageBox::Show("Матрицы на согласованны.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
						   return;
					   }
					   if (comboBox1->SelectedIndex == 0) {
						   double** tempResultMatrix = MultiplyNumOnMatrix(rows2M, columns2M, firstMatrix, secondMatrix);
						   DisplayMatrix(rows2M, columns2M, tempResultMatrix, textBoxesRM);
						   return;
					   }
					   double** tempResultMatrix = MultiplyMatrices(rows1M, columns1M, columns2M, firstMatrix, secondMatrix);
					   DisplayMatrix(rows1M, columns2M, tempResultMatrix, textBoxesRM);
				   }
			   }
		   }


	};
}