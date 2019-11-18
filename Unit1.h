//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Types.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Gestures.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.ImgList.hpp>
#include <FMX.Objects.hpp>
#include <System.ImageList.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Objects3D.hpp>
#include <System.Math.Vectors.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Edit.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <System.IOUtils.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TStyleBook *StyleBook1;
	TLayout *ToolbarHolder;
	TPopup *ToolbarPopup;
	TFloatAnimation *ToolbarPopupAnimation;
	TToolBar *ToolBar1;
	TButton *ToolbarCloseButton;
	TButton *FuelTypeAdd;
	TImage *FuelType1;
	TImage *FuelType2;
	TImage *FuelType3;
	TImage *FuelType4;
	TImage *FuelType5;
	TText *Text1;
	TRectangle *RunningText;
	TImage *Image1;
	TRectangle *FuelType;
	TFloatAnimation *RunningTextAnimation;
	TRectangle *UsualPrice;
	TImage *UsualPrice1;
	TImage *UsualPrice5;
	TImage *UsualPrice4;
	TImage *UsualPrice3;
	TImage *UsualPrice2;
	TText *UsualPriceText1;
	TText *UsualPriceMain1;
	TText *UsualPriceMain2;
	TText *UsualPriceText2;
	TText *UsualPriceMain3;
	TText *UsualPriceText3;
	TText *UsualPriceMain4;
	TText *UsualPriceText4;
	TText *UsualPriceMain5;
	TText *UsualPriceText5;
	TRectangle *PriceColumn1;
	TImage *PriceColumn11;
	TText *PriceColumnText11;
	TText *PriceColumnMain11;
	TImage *PriceColumn15;
	TText *PriceColumnMain15;
	TText *PriceColumnText15;
	TImage *PriceColumn14;
	TText *PriceColumnMain14;
	TText *PriceColumnText14;
	TImage *PriceColumn13;
	TText *PriceColumnMain13;
	TText *PriceColumnText13;
	TImage *PriceColumn12;
	TText *PriceColumnMain12;
	TText *PriceColumnText12;
	TRectangle *PriceColumn2;
	TImage *PriceColumn21;
	TText *PriceColumnText21;
	TText *PriceColumnMain21;
	TImage *PriceColumn25;
	TText *PriceColumnMain25;
	TText *PriceColumnText25;
	TImage *PriceColumn24;
	TText *PriceColumnMain24;
	TText *PriceColumnText24;
	TImage *PriceColumn23;
	TText *PriceColumnMain23;
	TText *PriceColumnText23;
	TImage *PriceColumn22;
	TText *PriceColumnMain22;
	TText *PriceColumnText22;
	TRectangle *PriceColumn3;
	TImage *PriceColumn31;
	TText *PriceColumnText31;
	TText *PriceColumnMain31;
	TImage *PriceColumn35;
	TText *PriceColumnMain35;
	TText *PriceColumnText35;
	TImage *PriceColumn34;
	TText *PriceColumnMain34;
	TText *PriceColumnText34;
	TImage *PriceColumn33;
	TText *PriceColumnMain33;
	TText *PriceColumnText33;
	TImage *PriceColumn32;
	TText *PriceColumnMain32;
	TText *PriceColumnText32;
	TText *FuelTypeText1;
	TText *FuelTypeText2;
	TText *FuelTypeText3;
	TText *FuelTypeText4;
	TText *FuelTypeText5;
	TTimer *ReadPrices;
	TFloatAnimation *AMain11;
	TFloatAnimation *AText11;
	TFloatAnimation *AMain12;
	TFloatAnimation *AText12;
	TFloatAnimation *AMain13;
	TFloatAnimation *AText13;
	TFloatAnimation *AMain14;
	TFloatAnimation *AText14;
	TFloatAnimation *AMain15;
	TFloatAnimation *AText15;
	TFloatAnimation *AMain21;
	TFloatAnimation *AText21;
	TFloatAnimation *AMain22;
	TFloatAnimation *AText22;
	TFloatAnimation *AMain23;
	TFloatAnimation *AText23;
	TFloatAnimation *AMain24;
	TFloatAnimation *AText24;
	TFloatAnimation *AMain25;
	TFloatAnimation *AText25;
	TFloatAnimation *AMain31;
	TFloatAnimation *AText31;
	TFloatAnimation *AMain32;
	TFloatAnimation *AText32;
	TFloatAnimation *AMain33;
	TFloatAnimation *AText33;
	TFloatAnimation *AMain34;
	TFloatAnimation *AText34;
	TFloatAnimation *AMain35;
	TFloatAnimation *AText35;
	TTimer *PricesAnimation;
	TButton *FuelTypeRemove;
	TLabel *FuelTypeOptionsText;
	TPanel *FuelTypeOptions;
	TPanel *RunningTextOptions;
	TLabel *RunningTextOptionsText;
	TButton *RunningTextRemove;
	TButton *RunningTextAdd;
	TComboColorBox *RunningTextColor;
	TPanel *ChangeRunningText;
	TEdit *ChangeRunningTextEdit;
	TButton *ChangeRunningTextButton;
	TButton *RunningTextEdit;
	TComboColorBox *FuelTypeTextColor;
	TPanel *DiscountThresholds;
	TLabel *DiscountThresholdsText;
	TComboColorBox *DiscountThresholdsColor;
	TButton *DiscountThresholdsAdd;
	TButton *DiscountThresholdsRemove;
	TPanel *PricesOptions;
	TLabel *PricesOptionsText;
	TComboColorBox *PricesOptionsColor;
	TButton *PricesOptionsRemove;
	TButton *PricesOptionsAdd;
	TPanel *AnimationSpeed;
	TLabel *AnimationSpeedText;
	TButton *PriceChangeAdd;
	TButton *PriceChangeRemove;
	TGroupBox *MonitorNumber;
	TRadioButton *Monitor1;
	TRadioButton *Monitor2;
	TRadioButton *Monitor3;
	TButton *MonitorApply;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
		  TShiftState Shift);
	void __fastcall ToolbarCloseButtonClick(TObject *Sender);
	void __fastcall FormGesture(TObject *Sender, const TGestureEventInfo &EventInfo,
          bool &Handled);
	void __fastcall FuelTypeResize(TObject *Sender);
	void __fastcall FuelType1Resize(TObject *Sender);
	void __fastcall RunningTextResize(TObject *Sender);
	void __fastcall FuelType2Resize(TObject *Sender);
	void __fastcall FuelType3Resize(TObject *Sender);
	void __fastcall FuelType4Resize(TObject *Sender);
	void __fastcall FuelType5Resize(TObject *Sender);
	void __fastcall Text1Resize(TObject *Sender);
	void __fastcall UsualPriceResize(TObject *Sender);
	void __fastcall UsualPrice1Resize(TObject *Sender);
	void __fastcall UsualPrice5Resize(TObject *Sender);
	void __fastcall UsualPrice4Resize(TObject *Sender);
	void __fastcall UsualPrice3Resize(TObject *Sender);
	void __fastcall UsualPrice2Resize(TObject *Sender);
	void __fastcall UsualPriceText1Resize(TObject *Sender);
	void __fastcall UsualPriceText2Resize(TObject *Sender);
	void __fastcall UsualPriceText3Resize(TObject *Sender);
	void __fastcall UsualPriceText4Resize(TObject *Sender);
	void __fastcall UsualPriceText5Resize(TObject *Sender);
	void __fastcall PriceColumn11Resize(TObject *Sender);
	void __fastcall PriceColumn1Resize(TObject *Sender);
	void __fastcall PriceColumn12Resize(TObject *Sender);
	void __fastcall PriceColumn13Resize(TObject *Sender);
	void __fastcall PriceColumn14Resize(TObject *Sender);
	void __fastcall PriceColumn15Resize(TObject *Sender);
	void __fastcall PriceColumnText11Resize(TObject *Sender);
	void __fastcall PriceColumnText12Resize(TObject *Sender);
	void __fastcall PriceColumnText13Resize(TObject *Sender);
	void __fastcall PriceColumnText14Resize(TObject *Sender);
	void __fastcall PriceColumnText15Resize(TObject *Sender);
	void __fastcall PriceColumn21Resize(TObject *Sender);
	void __fastcall PriceColumn2Resize(TObject *Sender);
	void __fastcall PriceColumn22Resize(TObject *Sender);
	void __fastcall PriceColumn23Resize(TObject *Sender);
	void __fastcall PriceColumn24Resize(TObject *Sender);
	void __fastcall PriceColumn25Resize(TObject *Sender);
	void __fastcall PriceColumnText21Resize(TObject *Sender);
	void __fastcall PriceColumnText22Resize(TObject *Sender);
	void __fastcall PriceColumnText23Resize(TObject *Sender);
	void __fastcall PriceColumnText24Resize(TObject *Sender);
	void __fastcall PriceColumnText25Resize(TObject *Sender);
	void __fastcall PriceColumn31Resize(TObject *Sender);
	void __fastcall PriceColumn3Resize(TObject *Sender);
	void __fastcall PriceColumn32Resize(TObject *Sender);
	void __fastcall PriceColumn33Resize(TObject *Sender);
	void __fastcall PriceColumn34Resize(TObject *Sender);
	void __fastcall PriceColumn35Resize(TObject *Sender);
	void __fastcall PriceColumnText31Resize(TObject *Sender);
	void __fastcall PriceColumnText32Resize(TObject *Sender);
	void __fastcall PriceColumnText33Resize(TObject *Sender);
	void __fastcall PriceColumnText34Resize(TObject *Sender);
	void __fastcall PriceColumnText35Resize(TObject *Sender);
	void __fastcall ReadPricesTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall PricesAnimationTimer(TObject *Sender);
	void __fastcall FuelTypeAddClick(TObject *Sender);
	void __fastcall FuelTypeRemoveClick(TObject *Sender);
	void __fastcall RunningTextAddClick(TObject *Sender);
	void __fastcall RunningTextRemoveClick(TObject *Sender);
	void __fastcall RunningTextColorChange(TObject *Sender);
	void __fastcall RunningTextEditClick(TObject *Sender);
	void __fastcall ChangeRunningTextButtonClick(TObject *Sender);
	void __fastcall FuelTypeTextColorChange(TObject *Sender);
	void __fastcall DiscountThresholdsAddClick(TObject *Sender);
	void __fastcall DiscountThresholdsRemoveClick(TObject *Sender);
	void __fastcall DiscountThresholdsColorChange(TObject *Sender);
	void __fastcall PricesOptionsColorChange(TObject *Sender);
	void __fastcall PricesOptionsAddClick(TObject *Sender);
	void __fastcall PricesOptionsRemoveClick(TObject *Sender);
	void __fastcall PriceChangeAddClick(TObject *Sender);
	void __fastcall PriceChangeRemoveClick(TObject *Sender);
	void __fastcall MonitorApplyClick(TObject *Sender);
private:	// User declarations
	TPointF FGestureOrigin;
	bool FGestureInProgress;
	void ShowToolbar(bool AShow);
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
