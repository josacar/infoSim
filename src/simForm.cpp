#include "simForm.h"

#include "FTelephony.h"
#include "FTelSimInfo.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Telephony;

simForm::simForm(void) {
}

simForm::~simForm(void) {
}

bool simForm::Initialize() {
	// Construct an XML form
	Construct(L"IDF_SIMFORM");

	return true;
}

result simForm::OnInitializing(void) {
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Get a button via resource ID
	__pButtonOk = static_cast<Button *> (GetControl(L"IDC_BUTTON_OK"));
	if (__pButtonOk != null) {
		__pButtonOk->SetActionId(ID_BUTTON_OK);
		__pButtonOk->AddActionEventListener(*this);
	}

	return r;
}

result simForm::OnTerminating(void) {
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void simForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {
	switch (actionId) {
	case ID_BUTTON_OK: {
		SimInfo *pSimInfo = new SimInfo();
		pSimInfo->Construct();

		bool isAvailable = pSimInfo->IsAvailable();
		EditField *valorIcc = static_cast<EditField *> (GetControl(
				L"IDC_EDITFIELDICC"));

		valorIcc->SetEnabled(false);

		if (isAvailable) {
			String iccId = pSimInfo->GetIccId();
			valorIcc->SetText(iccId);
			__pButtonOk->SetText("SUCCESS");
			AppLog("ICC Read! \n");
		} else {
			valorIcc->SetText("N/A");
			AppLog("SIM NOT READY! \n");
		}
	}
		break;
	default:
		break;
	}
	Draw();
	Show();
}

