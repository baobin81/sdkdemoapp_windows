
#include "application.h"
using namespace easemob;

EMClient *g_client;
bool Utils::g_bRosterDownloaded = false;
bool Utils::g_bGroupListDownloaded = false;
std::mutex Utils::roster_mutex;
std::mutex Utils::group_mutex;

void Utils::CallJS(const std::stringstream & stream)
{
	std::string strJSCall = stream.str();

	SimpleHandler *sh = SimpleHandler::GetInstance();
	if (sh != NULL)
	{
		CefRefPtr<CefBrowser> browser = sh->GetBrowser();
		if (browser.get())
		{
			CefRefPtr<CefFrame> frame = browser->GetMainFrame();
			if (frame.get())
			{
				frame->ExecuteJavaScript(strJSCall.c_str(), L"", 0);
			}
		}
	}
}