#ifndef _SIMFORM_H_
#define _SIMFORM_H_

#include <FBase.h>
#include <FUi.h>

class simForm :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener
{

// Construction
public:
	simForm(void);
	virtual ~simForm(void);
	bool Initialize(void);

// Implementation
protected:
	static const int ID_BUTTON_OK = 101;
	Osp::Ui::Controls::Button *__pButtonOk;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
};

#endif	//_SIMFORM_H_
