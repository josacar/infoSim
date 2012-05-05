/**
 * Name        : infoSim
 * Version     : 
 * Vendor      : 
 * Description : 
 */


#include "infoSim.h"
#include "simForm.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

infoSim::infoSim()
{
}

infoSim::~infoSim()
{
}

Application*
infoSim::CreateInstance(void)
{
	// Create the instance through the constructor.
	return new infoSim();
}

bool
infoSim::OnAppInitializing(AppRegistry& appRegistry)
{
	// TODO:
	// Initialize UI resources and application specific data.
	// The application's permanent data and context can be obtained from the appRegistry.
	//
	// If this method is successful, return true; otherwise, return false.
	// If this method returns false, the application will be terminated.

	// Uncomment the following statement to listen to the screen on/off events.
	//PowerManager::SetScreenEventListener(*this);

	// Create a form
	simForm *psimForm = new simForm();
	psimForm->Initialize();

	// Add the form to the frame
	Frame *pFrame = GetAppFrame()->GetFrame();
	pFrame->AddControl(*psimForm);

	// Set the current form
	pFrame->SetCurrentForm(*psimForm);

	// Draw and Show the form
	psimForm->Draw();
	psimForm->Show();

	return true;
}

bool
infoSim::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	// TODO:
	// Deallocate resources allocated by this application for termination.
	// The application's permanent data and context can be saved via appRegistry.
	return true;
}

void
infoSim::OnForeground(void)
{
	// TODO:
	// Start or resume drawing when the application is moved to the foreground.
}

void
infoSim::OnBackground(void)
{
	// TODO:
	// Stop drawing when the application is moved to the background.
}

void
infoSim::OnLowMemory(void)
{
	// TODO:
	// Free unused resources or close the application.
}

void
infoSim::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
	// TODO:
	// Handle any changes in battery level here.
	// Stop using multimedia features(camera, mp3 etc.) if the battery level is CRITICAL.
}

void
infoSim::OnScreenOn (void)
{
	// TODO:
	// Get the released resources or resume the operations that were paused or stopped in OnScreenOff().
}

void
infoSim::OnScreenOff (void)
{
	// TODO:
	//  Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode to save the battery.
	// Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a callback before the device enters the sleep mode.
	// Similarly, do not perform lengthy operations in this listener method. Any operation must be a quick one.
}
