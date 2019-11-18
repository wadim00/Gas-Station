//---------------------------------------------------------------------------

#include <fmx.h>


#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include "Unit1.h"
#include <windows.h>
#include <set>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <wchar.h>
#include <math.h>
#include <sstream>


#include "HDExport.h"
#pragma comment(lib, "HDSDK2.lib")

int LED_Monitor_SendText(float Diesel_Price, float A95_Price);






//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)

using namespace std;




TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FormGesture(TObject *Sender, const TGestureEventInfo &EventInfo,
		  bool &Handled)
{
	float DX, DY;

	if (EventInfo.GestureID == igiPan) {
		if (EventInfo.Flags.Contains(TInteractiveGestureFlag::gfBegin)
		  && (Sender == ToolbarPopup || EventInfo.Location.Y > (ClientHeight - 70))) {
			FGestureOrigin = EventInfo.Location;
			FGestureInProgress = true;
		}
	}

	if (FGestureInProgress && EventInfo.Flags.Contains(TInteractiveGestureFlag::gfEnd)) {
		FGestureInProgress = false;
		DX = EventInfo.Location.X - FGestureOrigin.X;
		DY = EventInfo.Location.Y - FGestureOrigin.Y;
		if (fabs(DY) > fabs(DX)) {
			ShowToolbar(DY < 0);
		}
	}
}
//---------------------------------------------------------------------------
void TMainForm::ShowToolbar(bool AShow)
{
  ToolbarPopup->Width = ClientWidth;
  ToolbarPopup->PlacementRectangle->Rect = TRect(MainForm->Left, ClientHeight-ToolbarPopup->Height+1500, MainForm->Width, MainForm->Height);
  ToolbarPopupAnimation->StartValue = ToolbarPopup->Height;
  ToolbarPopupAnimation->StopValue = 0;
  ToolbarPopup->IsOpen = AShow;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
		  TShiftState Shift)
{
  if (Key == vkEscape) {
	  ShowToolbar(!ToolbarPopup->IsOpen);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FuelTypeResize(TObject *Sender)
{
	FuelType->Width=MainForm->Width/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FuelType1Resize(TObject *Sender)
{
	FuelType1->Height=FuelType->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RunningTextResize(TObject *Sender)
{
	RunningText->Height=MainForm->Height/8;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FuelType2Resize(TObject *Sender)
{
	FuelType2->Height=FuelType->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FuelType3Resize(TObject *Sender)
{
	FuelType3->Height=FuelType->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FuelType4Resize(TObject *Sender)
{
	FuelType4->Height=FuelType->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FuelType5Resize(TObject *Sender)
{
	FuelType5->Height=FuelType->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Text1Resize(TObject *Sender)
{
   Text1->Width=4000;
   RunningTextAnimation->StartValue=MainForm->Width+10;
   RunningTextAnimation->StopValue=0-(Text1->Width+10);
}
//---------------------------------------------------------------------------

//
// Usual_price column
//

void __fastcall TMainForm::UsualPriceResize(TObject *Sender)
{
   UsualPrice->Width=MainForm->Width/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UsualPrice1Resize(TObject *Sender)
{
	UsualPrice1->Height=UsualPrice->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UsualPrice2Resize(TObject *Sender)
{
	UsualPrice2->Height=UsualPrice->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UsualPrice3Resize(TObject *Sender)
{
	UsualPrice3->Height=UsualPrice->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UsualPrice4Resize(TObject *Sender)
{
	UsualPrice4->Height=UsualPrice->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UsualPrice5Resize(TObject *Sender)
{
	UsualPrice5->Height=UsualPrice->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UsualPriceText1Resize(TObject *Sender)
{
  UsualPriceText1->Height=UsualPrice1->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UsualPriceText2Resize(TObject *Sender)
{
  UsualPriceText2->Height=UsualPrice2->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UsualPriceText3Resize(TObject *Sender)
{
  UsualPriceText3->Height=UsualPrice3->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UsualPriceText4Resize(TObject *Sender)
{
  UsualPriceText4->Height=UsualPrice4->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UsualPriceText5Resize(TObject *Sender)
{
  UsualPriceText5->Height=UsualPrice5->Height/4;
}
//---------------------------------------------------------------------------

//
// 1st Column methods
//

void __fastcall TMainForm::PriceColumn1Resize(TObject *Sender)
{
	PriceColumn1->Width=MainForm->Width/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn11Resize(TObject *Sender)
{
  PriceColumn11->Height=PriceColumn1->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn12Resize(TObject *Sender)
{
  PriceColumn12->Height=PriceColumn1->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn13Resize(TObject *Sender)
{
  PriceColumn13->Height=PriceColumn1->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn14Resize(TObject *Sender)
{
  PriceColumn14->Height=PriceColumn1->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn15Resize(TObject *Sender)
{
  PriceColumn15->Height=PriceColumn1->Height/5;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PriceColumnText11Resize(TObject *Sender)
{
  PriceColumnText11->Height=PriceColumn11->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumnText12Resize(TObject *Sender)
{
  PriceColumnText12->Height=PriceColumn12->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumnText13Resize(TObject *Sender)
{
  PriceColumnText13->Height=PriceColumn13->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumnText14Resize(TObject *Sender)
{
  PriceColumnText14->Height=PriceColumn14->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumnText15Resize(TObject *Sender)
{
  PriceColumnText15->Height=PriceColumn15->Height/4;
}
//---------------------------------------------------------------------------

//
// 2nd Column methods
//

void __fastcall TMainForm::PriceColumn2Resize(TObject *Sender)
{
	PriceColumn2->Width=MainForm->Width/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn21Resize(TObject *Sender)
{
  PriceColumn21->Height=PriceColumn2->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn22Resize(TObject *Sender)
{
  PriceColumn22->Height=PriceColumn2->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn23Resize(TObject *Sender)
{
  PriceColumn23->Height=PriceColumn2->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn24Resize(TObject *Sender)
{
  PriceColumn24->Height=PriceColumn2->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn25Resize(TObject *Sender)
{
  PriceColumn25->Height=PriceColumn2->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumnText21Resize(TObject *Sender)
{
  PriceColumnText21->Height=PriceColumn21->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumnText22Resize(TObject *Sender)
{
  PriceColumnText22->Height=PriceColumn22->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumnText23Resize(TObject *Sender)
{
  PriceColumnText23->Height=PriceColumn23->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumnText24Resize(TObject *Sender)
{
  PriceColumnText24->Height=PriceColumn24->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumnText25Resize(TObject *Sender)
{
  PriceColumnText25->Height=PriceColumn25->Height/4;
}
//---------------------------------------------------------------------------

//
// 3rd Column methods
//

void __fastcall TMainForm::PriceColumn3Resize(TObject *Sender)
{
	PriceColumn3->Width=MainForm->Width/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn31Resize(TObject *Sender)
{
  PriceColumn31->Height=PriceColumn3->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn32Resize(TObject *Sender)
{
  PriceColumn32->Height=PriceColumn3->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn33Resize(TObject *Sender)
{
  PriceColumn33->Height=PriceColumn3->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn34Resize(TObject *Sender)
{
  PriceColumn34->Height=PriceColumn3->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumn35Resize(TObject *Sender)
{
  PriceColumn35->Height=PriceColumn3->Height/5;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumnText31Resize(TObject *Sender)
{
  PriceColumnText31->Height=PriceColumn31->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumnText32Resize(TObject *Sender)
{
  PriceColumnText32->Height=PriceColumn32->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumnText33Resize(TObject *Sender)
{
  PriceColumnText33->Height=PriceColumn33->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumnText34Resize(TObject *Sender)
{
  PriceColumnText34->Height=PriceColumn34->Height/4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriceColumnText35Resize(TObject *Sender)
{
  PriceColumnText35->Height=PriceColumn35->Height/4;

}
//---------------------------------------------------------------------------
set<string> FuelTypes;
string FileWithPrices="Price.txt";

filesystem::path PricesPath = filesystem::current_path()/filesystem::path(FileWithPrices);
auto LastFileChange = filesystem::last_write_time(PricesPath);
time_t FileTime = decltype(LastFileChange)::clock::to_time_t(LastFileChange);

filesystem::file_time_type LastFileChangeBuf;
time_t FileTimeBuf;

bool flag=false; //Ïðàïîðåöü äëÿ ïåðåâ³ðêè ÷è ì³ñòèòü âåêòîð îá'ºêò³â, îá'ºêò ç òèïîì ïàëèâà

void ReadFuelType ()
{
  string line_buf="",buf="";
  ifstream file(FileWithPrices);
  while(!file.eof())
  {
	getline(file,line_buf);
	if (line_buf!="")
	{

		for (int i = 0; i < line_buf.length() ; i++)
		{
			if(line_buf[i]!=';')
			{
				buf+=line_buf[i];
			}
			else
			{
			break;
			}
		}

		if (FuelTypes.size()==0)
		{
			FuelTypes.insert(buf);
		}
		else
		if (FuelTypes.find(buf) == FuelTypes.end())
		{
			FuelTypes.insert(buf);
		}
	}
	buf="";
  }
  file.close();
}

class Price
{
  private:

  string FuelType;
  float UsualPrice;
  set<float> Prices;
  set<int> PricesLevels;

  public:

   Price(const Price &obj)
   {

   }
   Price(string FuelType)
   {
	this->FuelType=FuelType;
   }

   void SetPrices(string filename)
  {
	string line_buf="",pricebuf="",levelbuf="",fueltypebuf="";
	int count=0;
	this->UsualPrice=0;
	this->Prices.clear();
    this->PricesLevels.clear();
	ifstream file(filename);
	while(!file.eof())
	{
		getline(file,line_buf);

		if (line_buf.find(FuelType)!=string::npos)
		{
			for (int i = 0; i < line_buf.length(); i++)
			{
			  if (line_buf[i]==';')
			  {
			   count++;
			  }
			  else
			  if (count<1)
			  {
			   fueltypebuf+=line_buf[i];
			  }
			  else
			  if (count==1)
			  {
			   levelbuf+=line_buf[i];
			  }
			  else
			  if (count==3)
			  {
			   pricebuf+=line_buf[i];
			  }
			}

			if (stoi(levelbuf)==0 && this->FuelType==fueltypebuf )
			{
			  this->UsualPrice=stof(pricebuf);
			}
			else
			if (this->FuelType==fueltypebuf )
			{
			 PricesLevels.insert(stoi(levelbuf));
			 Prices.insert(stof(pricebuf));
			}
			line_buf="";
			pricebuf="";
			levelbuf="";
			fueltypebuf="";
			count=0;

		}

	}
	file.close();


  }
   auto GetPrices(int PricesNumber)
   {
	auto it=Prices.end();
	for (int i = 0; i <=PricesNumber; i++)
	{
	 it--;
	}
	return *it;
   }
   auto GetPricesSize()
   {
	return this->Prices.size();
   }
   auto GetPricesLevels(int LevelsNumber)
   {
	auto it=PricesLevels.begin();
	for (int i = 0; i <LevelsNumber; i++)
	{
	 it++;
	}
	return *it;
   }
   float GetUsualPrice()
   {
	return this->UsualPrice;
   }
   string GetFuelType()
   {
	return this->FuelType;
   }


  ~Price()
   {}
};

vector<shared_ptr<Price>> Prices;
vector<Fmx::Objects::TText*> FuelTypeObjects;
vector<Fmx::Objects::TText*> UsualPrices;
vector<Fmx::Objects::TText*> UsualPricesText;
vector<Fmx::Objects::TText*> PriceColumn1Mains;
vector<Fmx::Objects::TText*> PriceColumn1Texts;
vector<Fmx::Objects::TText*> PriceColumn2Mains;
vector<Fmx::Objects::TText*> PriceColumn2Texts;
vector<Fmx::Objects::TText*> PriceColumn3Mains;
vector<Fmx::Objects::TText*> PriceColumn3Texts;
vector<Fmx::Ani::TFloatAnimation*> AMain1;
vector<Fmx::Ani::TFloatAnimation*> AText1;
vector<Fmx::Ani::TFloatAnimation*> AMain2;
vector<Fmx::Ani::TFloatAnimation*> AText2;
vector<Fmx::Ani::TFloatAnimation*> AMain3;
vector<Fmx::Ani::TFloatAnimation*> AText3;
int maxsize=0;
int monitor=0;





//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
  FuelTypeObjects.push_back(FuelTypeText1);
  FuelTypeObjects.push_back(FuelTypeText2);
  FuelTypeObjects.push_back(FuelTypeText3);
  FuelTypeObjects.push_back(FuelTypeText4);
  FuelTypeObjects.push_back(FuelTypeText5);

  UsualPrices.push_back(UsualPriceMain1);
  UsualPrices.push_back(UsualPriceMain2);
  UsualPrices.push_back(UsualPriceMain3);
  UsualPrices.push_back(UsualPriceMain4);
  UsualPrices.push_back(UsualPriceMain5);

  UsualPricesText.push_back(UsualPriceText1);
  UsualPricesText.push_back(UsualPriceText2);
  UsualPricesText.push_back(UsualPriceText3);
  UsualPricesText.push_back(UsualPriceText4);
  UsualPricesText.push_back(UsualPriceText5);

  PriceColumn1Mains.push_back(PriceColumnMain11);
  PriceColumn1Mains.push_back(PriceColumnMain12);
  PriceColumn1Mains.push_back(PriceColumnMain13);
  PriceColumn1Mains.push_back(PriceColumnMain14);
  PriceColumn1Mains.push_back(PriceColumnMain15);

  PriceColumn1Texts.push_back(PriceColumnText11);
  PriceColumn1Texts.push_back(PriceColumnText12);
  PriceColumn1Texts.push_back(PriceColumnText13);
  PriceColumn1Texts.push_back(PriceColumnText14);
  PriceColumn1Texts.push_back(PriceColumnText15);

  PriceColumn2Mains.push_back(PriceColumnMain21);
  PriceColumn2Mains.push_back(PriceColumnMain22);
  PriceColumn2Mains.push_back(PriceColumnMain23);
  PriceColumn2Mains.push_back(PriceColumnMain24);
  PriceColumn2Mains.push_back(PriceColumnMain25);

  PriceColumn2Texts.push_back(PriceColumnText21);
  PriceColumn2Texts.push_back(PriceColumnText22);
  PriceColumn2Texts.push_back(PriceColumnText23);
  PriceColumn2Texts.push_back(PriceColumnText24);
  PriceColumn2Texts.push_back(PriceColumnText25);

  PriceColumn3Mains.push_back(PriceColumnMain31);
  PriceColumn3Mains.push_back(PriceColumnMain32);
  PriceColumn3Mains.push_back(PriceColumnMain33);
  PriceColumn3Mains.push_back(PriceColumnMain34);
  PriceColumn3Mains.push_back(PriceColumnMain35);

  PriceColumn3Texts.push_back(PriceColumnText31);
  PriceColumn3Texts.push_back(PriceColumnText32);
  PriceColumn3Texts.push_back(PriceColumnText33);
  PriceColumn3Texts.push_back(PriceColumnText34);
  PriceColumn3Texts.push_back(PriceColumnText35);

  AMain1.push_back(AMain11);
  AMain1.push_back(AMain12);
  AMain1.push_back(AMain13);
  AMain1.push_back(AMain14);
  AMain1.push_back(AMain15);

  AText1.push_back(AText11);
  AText1.push_back(AText12);
  AText1.push_back(AText13);
  AText1.push_back(AText14);
  AText1.push_back(AText15);

  AMain2.push_back(AMain21);
  AMain2.push_back(AMain22);
  AMain2.push_back(AMain23);
  AMain2.push_back(AMain24);
  AMain2.push_back(AMain25);

  AText2.push_back(AText21);
  AText2.push_back(AText22);
  AText2.push_back(AText23);
  AText2.push_back(AText24);
  AText2.push_back(AText25);

  AMain3.push_back(AMain31);
  AMain3.push_back(AMain32);
  AMain3.push_back(AMain33);
  AMain3.push_back(AMain34);
  AMain3.push_back(AMain35);

  AText3.push_back(AText31);
  AText3.push_back(AText32);
  AText3.push_back(AText33);
  AText3.push_back(AText34);
  AText3.push_back(AText35);

   string finbuffer="";
   ifstream fin("ini.txt");

   getline(fin,finbuffer);
   monitor=stoi(finbuffer);

   getline(fin,finbuffer);
   PricesAnimation->Interval=stoi(finbuffer);

   getline(fin,finbuffer);
   Text1->Text=finbuffer.c_str();

   getline(fin,finbuffer);
   Text1->TextSettings->FontColor=stoul(finbuffer);

   getline(fin,finbuffer);
   Text1->Font->Size=stoi(finbuffer);

   for (int i = 0; i < FuelTypeObjects.size(); i++)
	{
		getline(fin,finbuffer);
		UsualPrices[i]->Font->Size=stoi(finbuffer);
		getline(fin,finbuffer);
		PriceColumn1Mains[i]->Font->Size=stoi(finbuffer);
		getline(fin,finbuffer);
		PriceColumn2Mains[i]->Font->Size=stoi(finbuffer);
		getline(fin,finbuffer);
		PriceColumn3Mains[i]->Font->Size=stoi(finbuffer);

		getline(fin,finbuffer);
		UsualPricesText[i]->Font->Size=stoi(finbuffer);
		getline(fin,finbuffer);
		PriceColumn1Texts[i]->Font->Size=stoi(finbuffer);
		getline(fin,finbuffer);
		PriceColumn2Texts[i]->Font->Size=stoi(finbuffer);
		getline(fin,finbuffer);
		PriceColumn3Texts[i]->Font->Size=stoi(finbuffer);

		getline(fin,finbuffer);
		UsualPrices[i]->TextSettings->FontColor=stoul(finbuffer);
		getline(fin,finbuffer);
		PriceColumn1Mains[i]->TextSettings->FontColor=stoul(finbuffer);
		getline(fin,finbuffer);
		PriceColumn2Mains[i]->TextSettings->FontColor=stoul(finbuffer);
		getline(fin,finbuffer);
		PriceColumn3Mains[i]->TextSettings->FontColor=stoul(finbuffer);

		getline(fin,finbuffer);
		UsualPricesText[i]->TextSettings->FontColor=stoul(finbuffer);
		getline(fin,finbuffer);
		PriceColumn1Texts[i]->TextSettings->FontColor=stoul(finbuffer);
		getline(fin,finbuffer);
		PriceColumn2Texts[i]->TextSettings->FontColor=stoul(finbuffer);
		getline(fin,finbuffer);
		PriceColumn3Texts[i]->TextSettings->FontColor=stoul(finbuffer);

		getline(fin,finbuffer);
		FuelTypeObjects[i]->TextSettings->FontColor=stoul(finbuffer);
		getline(fin,finbuffer);
		FuelTypeObjects[i]->Font->Size=stoi(finbuffer);
	}
	fin.close();

  ReadFuelType();
  for (auto i = FuelTypes.begin(); i != FuelTypes.end(); ++i)
  {
	Prices.push_back(shared_ptr<Price>(new Price(*i)));
  }

  for (int i = 0; i < Prices.size(); i++)
  {
	Prices[i]->SetPrices(FileWithPrices);
	FuelTypeObjects[i]->Text = Prices[i]->GetFuelType().c_str();
	UsualPrices[i]->Text = System::UnicodeString::FloatToStrF(Prices[i]->GetUsualPrice(),System::UnicodeString::TStringFloatFormat::sffFixed,4,2);
    UsualPricesText[i]->Text="Çâè÷àéíà ö³íà";
	if (Prices[i]->GetPricesSize()>maxsize)
	{
	 maxsize = Prices[i]->GetPricesSize();
	}
  }
  auto bounds=Fmx::Forms::TScreen::Displays[monitor];
  MainForm->SetBounds(bounds.BoundsRect);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ReadPricesTimer(TObject *Sender)
{

  LastFileChangeBuf = filesystem::last_write_time(PricesPath);
  FileTimeBuf = decltype(LastFileChangeBuf)::clock::to_time_t(LastFileChangeBuf);

  if (FileTimeBuf>FileTime)
  {
	LastFileChange=filesystem::last_write_time(PricesPath);
	FileTime=decltype(LastFileChange)::clock::to_time_t(LastFileChange);

	ReadFuelType();
	//Prices.reserve(FuelTypes.size());
	for (auto i = FuelTypes.begin(); i != FuelTypes.end(); ++i)
	{

		for (int j = 0; j < Prices.size(); j++)
		{

			if (*i == Prices[j]->GetFuelType())
			{
			  flag = false;
			  break;
			}
			else
			{
			  flag=true;
			}

		}
		if (flag)
		{
             Prices.push_back(shared_ptr<Price>(new Price(*i)));
		}

	}

	for (int i = 0; i < FuelTypeObjects.size(); i++)
	{
		FuelTypeObjects[i]->Text="";
		UsualPrices[i]->Text="";
	 	UsualPricesText[i]->Text="";
	}
	//Áóôåðè çáåðåæåííÿ ö³í äëÿ âèâåäåííÿ íà LED òàáëî
	float LED_Usual_Price_A95=0.0;
	float LED_Usual_Price_Diesel=0.0;

	for (int i = 0; i < Prices.size(); i++)
	{
		Prices[i]->SetPrices(FileWithPrices);
		FuelTypeObjects[i]->Text = Prices[i]->GetFuelType().c_str();
		UsualPrices[i]->Text = System::UnicodeString::FloatToStrF(Prices[i]->GetUsualPrice(),System::UnicodeString::TStringFloatFormat::sffFixed,4,2);
		UsualPricesText[i]->Text="Çâè÷àéíà ö³íà";
		//Âñòàíîâëåííÿ áóôåð³â äëÿ âèâåäåííÿ ö³í íà LED òàáëà
		if (Prices[i]->GetFuelType()=="À-95")
		{
		   LED_Usual_Price_A95=Prices[i]->GetUsualPrice();
		}
		if (Prices[i]->GetFuelType()=="ÄÏ ªâðî")
		{
		   LED_Usual_Price_Diesel=Prices[i]->GetUsualPrice();
		}
	}
	LED_Monitor_SendText(LED_Usual_Price_Diesel, LED_Usual_Price_A95);
  }

}

int casecount =1; //ë³÷èëüíèê ïåðåõîä³â ïî ñòîâïöÿõ
int row=0;
void __fastcall TMainForm::PricesAnimationTimer(TObject *Sender)
{
  switch (casecount)
  {
	case 1:
	{
		for (int i = 0; i < Prices.size(); i++)
		{
			if (row<maxsize && row<Prices[i]->GetPricesSize())
			{

				PriceColumn1Mains[i]->Text = System::UnicodeString::FloatToStrF(Prices[i]->GetPrices(row),System::UnicodeString::TStringFloatFormat::sffFixed,4,2);
				PriceColumn1Texts[i]->Text = "Â³ä " + (String)Prices[i]->GetPricesLevels(row) + " ë³òð³â";
			}
			else
			if (row>=maxsize)
			{
				casecount=5;
			}
		}
		row++;
		casecount++;
		break;
	}
	case 2:
	{
		for (int i = 0; i < Prices.size(); i++)
		{
			if (row<maxsize && row<Prices[i]->GetPricesSize())
			{
				PriceColumn2Mains[i]->Text = System::UnicodeString::FloatToStrF(Prices[i]->GetPrices(row),System::UnicodeString::TStringFloatFormat::sffFixed,4,2);
				PriceColumn2Texts[i]->Text = "Â³ä " + (String)Prices[i]->GetPricesLevels(row) + " ë³òð³â";
			}
			else
			if (row>=maxsize)
			{
				casecount=5;
			}
		}
		row++;
		casecount++;
		break;
	}
	case 3:
	{
		for (int i = 0; i < Prices.size(); i++)
		{
			if (row<maxsize && row<Prices[i]->GetPricesSize())
			{
				cout<<setprecision(2);
				PriceColumn3Mains[i]->Text = System::UnicodeString::FloatToStrF(Prices[i]->GetPrices(row),System::UnicodeString::TStringFloatFormat::sffFixed,4,2);
				PriceColumn3Texts[i]->Text = "Â³ä " + (String)Prices[i]->GetPricesLevels(row) + " ë³òð³â";
			}
			else
			if (row>=maxsize)
			{
				casecount=5;
			}
		}
		row++;
		casecount++;
	 break;
	}
	case 4:
	{
		for (int i = 0; i < Prices.size(); i++)
		{
			if (row<maxsize && row<Prices[i]->GetPricesSize())
			{
				PriceColumn1Mains[i]->Text = "";
				PriceColumn1Texts[i]->Text = "";
				PriceColumn2Mains[i]->Text = "";
				PriceColumn2Texts[i]->Text = "";
				PriceColumn3Mains[i]->Text = "";
				PriceColumn3Texts[i]->Text = "";
			}

		}
        casecount=1;
	 break;
	}

	default:
	{
        for (int i = 0; i < Prices.size(); i++)
		{
				PriceColumn1Mains[i]->Text = "";
				PriceColumn1Texts[i]->Text = "";
				PriceColumn2Mains[i]->Text = "";
				PriceColumn2Texts[i]->Text = "";
				PriceColumn3Mains[i]->Text = "";
				PriceColumn3Texts[i]->Text = "";
		}
		casecount=1;
		row=0;
	}
  }

 //  PriceColumn1Mains[i]->Text=Prices[i]->GetPrices(0);










}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FuelTypeAddClick(TObject *Sender)
{
	for (int i = 0; i < FuelTypeObjects.size(); i++)
	{
		FuelTypeObjects[i]->Font->Size+=1;
  		FuelTypeObjects[i]->Width=FuelType1->Width;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FuelTypeRemoveClick(TObject *Sender)
{
	for (int i = 0; i < FuelTypeObjects.size(); i++)
	{
		FuelTypeObjects[i]->Font->Size-=1;
		FuelTypeObjects[i]->Width=FuelType1->Width;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RunningTextAddClick(TObject *Sender)
{
	Text1->Font->Size+=1;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RunningTextRemoveClick(TObject *Sender)
{
	Text1->Font->Size-=1;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::RunningTextColorChange(TObject *Sender)
{
	Text1->TextSettings->FontColor=RunningTextColor->Color;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RunningTextEditClick(TObject *Sender)
{
	ShowToolbar(0);
	ChangeRunningText->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ChangeRunningTextButtonClick(TObject *Sender)
{
	Text1->Text=ChangeRunningTextEdit->Text;
	ChangeRunningText->Visible=false;
	ShowToolbar(1);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FuelTypeTextColorChange(TObject *Sender)
{
	for (int i = 0; i < FuelTypeObjects.size(); i++)
	{
		FuelTypeObjects[i]->TextSettings->FontColor=FuelTypeTextColor->Color;
	}
}
//----------------------------------------------------------------------------

void __fastcall TMainForm::DiscountThresholdsAddClick(TObject *Sender)
{
	for (int i = 0; i < FuelTypeObjects.size(); i++)
	{
		UsualPricesText[i]->Font->Size+=1;
		PriceColumn1Texts[i]->Font->Size+=1;
		PriceColumn2Texts[i]->Font->Size+=1;
		PriceColumn3Texts[i]->Font->Size+=1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DiscountThresholdsRemoveClick(TObject *Sender)
{
	for (int i = 0; i < FuelTypeObjects.size(); i++)
	{
		UsualPricesText[i]->Font->Size-=1;
		PriceColumn1Texts[i]->Font->Size-=1;
		PriceColumn2Texts[i]->Font->Size-=1;
		PriceColumn3Texts[i]->Font->Size-=1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DiscountThresholdsColorChange(TObject *Sender)
{
	for (int i = 0; i < FuelTypeObjects.size(); i++)
	{
		UsualPricesText[i]->TextSettings->FontColor=DiscountThresholdsColor->Color;
		PriceColumn1Texts[i]->TextSettings->FontColor=DiscountThresholdsColor->Color;
		PriceColumn2Texts[i]->TextSettings->FontColor=DiscountThresholdsColor->Color;
		PriceColumn3Texts[i]->TextSettings->FontColor=DiscountThresholdsColor->Color;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PricesOptionsColorChange(TObject *Sender)
{
	for (int i = 0; i < FuelTypeObjects.size(); i++)
	{
		UsualPrices[i]->TextSettings->FontColor=PricesOptionsColor->Color;
		PriceColumn1Mains[i]->TextSettings->FontColor=PricesOptionsColor->Color;
		PriceColumn2Mains[i]->TextSettings->FontColor=PricesOptionsColor->Color;
		PriceColumn3Mains[i]->TextSettings->FontColor=PricesOptionsColor->Color;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PricesOptionsAddClick(TObject *Sender)
{
	for (int i = 0; i < FuelTypeObjects.size(); i++)
	{
		UsualPrices[i]->Font->Size+=1;
		PriceColumn1Mains[i]->Font->Size+=1;
		PriceColumn2Mains[i]->Font->Size+=1;
		PriceColumn3Mains[i]->Font->Size+=1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PricesOptionsRemoveClick(TObject *Sender)
{
	for (int i = 0; i < FuelTypeObjects.size(); i++)
	{
		UsualPrices[i]->Font->Size-=1;
		PriceColumn1Mains[i]->Font->Size-=1;
		PriceColumn2Mains[i]->Font->Size-=1;
		PriceColumn3Mains[i]->Font->Size-=1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PriceChangeAddClick(TObject *Sender)
{
	PricesAnimation->Enabled=false;
	PricesAnimation->Interval-=100;
	PricesAnimation->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PriceChangeRemoveClick(TObject *Sender)
{
	PricesAnimation->Enabled=false;
	PricesAnimation->Interval+=100;
	PricesAnimation->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MonitorApplyClick(TObject *Sender)
{
  if (Monitor1->IsChecked )
  {
	monitor=0;
  }
  else
  if (Monitor2->IsChecked )
  {
	monitor=1;
  }
  else
  if (Monitor3->IsChecked )
  {
	monitor=3;
  }
  auto bounds=Fmx::Forms::TScreen::Displays[monitor];
  MainForm->SetBounds(bounds.BoundsRect);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolbarCloseButtonClick(TObject *Sender)
{
   AnsiString str=Text1->Text;
   std::string RunningTextbuf(str.c_str());
   ofstream fout("ini.txt");
   fout<<monitor<<endl;
   fout<<PricesAnimation->Interval<<endl;
   fout<<RunningTextbuf<<endl;
   fout<<Text1->TextSettings->FontColor<<endl;
   fout<<Text1->Font->Size<<endl;
   for (int i = 0; i < FuelTypeObjects.size(); i++)
	{
		fout<<UsualPrices[i]->Font->Size<<endl;
		fout<<PriceColumn1Mains[i]->Font->Size<<endl;
		fout<<PriceColumn2Mains[i]->Font->Size<<endl;
		fout<<PriceColumn3Mains[i]->Font->Size<<endl;

		fout<<UsualPricesText[i]->Font->Size<<endl;
		fout<<PriceColumn1Texts[i]->Font->Size<<endl;
		fout<<PriceColumn2Texts[i]->Font->Size<<endl;
		fout<<PriceColumn3Texts[i]->Font->Size<<endl;

		fout<<UsualPrices[i]->TextSettings->FontColor<<endl;
		fout<<PriceColumn1Mains[i]->TextSettings->FontColor<<endl;
		fout<<PriceColumn2Mains[i]->TextSettings->FontColor<<endl;
		fout<<PriceColumn3Mains[i]->TextSettings->FontColor<<endl;

		fout<<UsualPricesText[i]->TextSettings->FontColor<<endl;
		fout<<PriceColumn1Texts[i]->TextSettings->FontColor<<endl;
		fout<<PriceColumn2Texts[i]->TextSettings->FontColor<<endl;
		fout<<PriceColumn3Texts[i]->TextSettings->FontColor<<endl;

		fout<<FuelTypeObjects[i]->TextSettings->FontColor<<endl;
		fout<<FuelTypeObjects[i]->Font->Size<<endl;
	}
	fout.close();

   _exit(0);
}
//---------------------------------------------------------------------------
 int LED_Monitor_SendText(float Diesel_Price, float A95_Price)
{
 int nError = 0;
 // 1. Create a screen
 int nWidth = 768;
 int nHeight = 48;
 int nColor = 0;
 int nGray = 1;
 int nCardType = 58;

 int nRe = Hd_CreateScreen(nWidth, nHeight, nColor, nGray, nCardType, 0, 0);
 if (nRe != 0)
 {
  cout<<"Hd_CreateScreen error!\n"<<nRe;
  return -1;
 }

 // 2. Add program to screen
 int nProgramID = Hd_AddProgram(0, 0, 5, 0, 0);
 if (nProgramID == -1)
 {
  nError = Hd_GetSDKLastError();
  cout<<"Hd_AddProgram error!\n"<<nError;
  return -1;
 }

 /////////////////////////////////////////////////////////////////////////////
 //////////////////////// ÍÀËÀØÒÓÂÀÍÍß Ë²ÂÎÃÎ ÂÅÐÕÍÜÎÃÎ ÒÀÁËÀ////////////////
 int nX = 0;
 int nY = 0;
 int nAreaWidth = 192;
 int nAreaHeight = 48;

 // 3. Add Area to program ()
 int nAreaID = Hd_AddArea(nProgramID, nX, nY, nAreaWidth, nAreaHeight, 0, 0, 5, 0, 0);
 if (nAreaID == -1)
 {
  nError = Hd_GetSDKLastError();
  cout<<"Hd_AddAreaLeftUpScreen error"<<nError;
  return -1;
 }

 // 4.Add text AreaItem to Area


 wchar_t * szText=L"ÂÈÑÎÊÀ ßÊ²ÑÒÜ ÍÈÇÜÊ² Ö²ÍÈ. ÏÐÎÄÀÆ ÒÀËÎÍ²Â.";
 wchar_t * pFont=L"Arial";
 int nFontColor = Hd_GetColor(255,0,0);
 int nAreaItemID = Hd_AddSimpleTextAreaItem(nAreaID, szText, nFontColor, 0, 7|0x0100, pFont, 45, 202, 10, 201, 0, 0, 0);
 if (nAreaItemID == -1)
 {
  nError = Hd_GetSDKLastError();
  cout<<"Hd_AddSimpleTextAreaLeftUpScreen error"<<nError;
  return -1;
 }
 //////////////////////////////////////////////////////////////////////////////

 /////////////////////////////////////////////////////////////////////////////
 /////////////////////ÍÀËÀØÒÓÂÀÍÍß Ë²ÂÎÃÎ ÍÈÆÍÜÎÃÎ ÒÀÁËÀ//////////////////////
  nX = 192;
  nY = 0;
  nAreaWidth = 192;
  nAreaHeight = 48;

 // 3. Add Area to program ()
 nAreaID = Hd_AddArea(nProgramID, nX, nY, nAreaWidth, nAreaHeight, 0, 0, 5, 0, 0);
 if (nAreaID == -1)
 {
  nError = Hd_GetSDKLastError();
  cout<<"Hd_AddAreaLeftDownScreen error"<<nError;
  return -1;
 }

  wchar_t diesel[8];
  std::wcsncpy(diesel, L"ÄÏ ", 8);
  std::stringstream ssDiesel;
  ssDiesel.precision(2);
  ssDiesel.setf( std::ios::fixed, std:: ios::floatfield );
  ssDiesel<<Diesel_Price;
  std::string s = ssDiesel.str();
  std::wstring wstringDiesel( s.begin(), s.end() );
  wchar_t * wstrDiesel=const_cast<wchar_t *>(wstringDiesel.c_str());
  wcscat(diesel, wstrDiesel);
  ssDiesel.clear();
 // 4.Add text AreaItem to Area
 nAreaItemID = Hd_AddSimpleTextAreaItem(nAreaID, diesel, nFontColor, 0, 4|0x0100, pFont, 45, 0, 25, 201, 0, 0, 0);

 if (nAreaItemID == -1)
 {
  nError = Hd_GetSDKLastError();
  cout<<"Hd_AddSimpleTextAreaLeftDownScreen error"<<nError;
  return -1;
 }
 //////////////////////////////////////////////////////////////////////////////
 /////////////////////ÍÀËÀØÒÓÂÀÍÍß ÏÐÀÂÎÃÎ ÂÅÐÕÍÜÎÃÎ ÒÀÁËÀ//////////////////////
  nX = 576;
  nY = 0;
  nAreaWidth = 192;
  nAreaHeight = 48;

 // 3. Add Area to program ()
 nAreaID = Hd_AddArea(nProgramID, nX, nY, nAreaWidth, nAreaHeight, 0, 0, 5, 0, 0);
 if (nAreaID == -1)
 {
  nError = Hd_GetSDKLastError();
  cout<<"Hd_AddAreaRightUpScreen error"<<nError;
  return -1;
 }

 // 4.Add text AreaItem to Area
 szText=L"Âàñ â³òàº OkOil";
 nAreaItemID = Hd_AddSimpleTextAreaItem(nAreaID, szText, nFontColor, 0, 4|0x0100, pFont, 47, 202, 10, 201, 0, 0, 0);
 if (nAreaItemID == -1)
 {
  nError = Hd_GetSDKLastError();
  cout<<"Hd_AddSimpleTextAreaRightUpScreen error"<<nError;
  return -1;
 }
 //////////////////////////////////////////////////////////////////////////////
 /////////////////////ÍÀËÀØÒÓÂÀÍÍß ÏÐÀÂÎÃÎ ÍÈÆÍÜÎÃÎ ÒÀÁËÀ//////////////////////
  nX = 382;
  nY = 0;
  nAreaWidth = 192;
  nAreaHeight = 48;

 // 3. Add Area to program ()
 nAreaID = Hd_AddArea(nProgramID, nX, nY, nAreaWidth, nAreaHeight, 0, 0, 5, 0, 0);
 if (nAreaID == -1)
 {
  nError = Hd_GetSDKLastError();
  cout<<"Hd_AddAreaRightDownScreen error"<<nError;
  return -1;
 }

// 4.Add text AreaItem to Area
  wchar_t A95[8];
  std::wcsncpy(A95, L"95 ", 8);
  std::stringstream ssA95;
  ssA95.precision(2);
  ssA95.setf( std::ios::fixed, std:: ios::floatfield );
  ssA95<<A95_Price;
  s = ssA95.str();
  std::wstring wstringA95( s.begin(), s.end() );
  wchar_t * wstrA95=const_cast<wchar_t *>(wstringA95.c_str());
  wcscat(A95, wstrA95);
  ssA95.clear();
  nAreaItemID = Hd_AddSimpleTextAreaItem(nAreaID, A95, nFontColor, 0, 4|0x0100, pFont, 45, 0, 25, 201, 0, 0, 0);

 if (nAreaItemID == -1)
 {
  nError = Hd_GetSDKLastError();
  cout<<"Hd_AddSimpleTextAreaRightDownScreen error"<<nError;
  return -1;
 }
 //////////////////////////////////////////////////////////////////////////////

 // Save Screen File
 //nRe = Hd_SaveScreen(L"D:\\");
 //if(nRe !=0 )
 //{
 // nError = Hd_GetSDKLastError();
 //}

 wchar_t * ip=L"192.168.0.115:6101";
 wchar_t * zero=L"0";
 bool bSendTcp = true;
 if (bSendTcp)
 {
  // Send to device use tcp
  nRe = Hd_SendScreen(0,ip, 0, 0, 0);

  if (nRe == -1)
  {
   nError = Hd_GetSDKLastError();

   cout<<nError;
  }
 }

 return 0;
}






