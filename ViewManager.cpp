#include "ViewManager.h"

ViewManager::ViewManager(WindowManager *window)
{
	this->window = window;
	this->viewName = viewName;
}

ViewManager::~ViewManager()
{
}

void ViewManager::initView()
{

}

void ViewManager::drawCurrentView()
{
	for (unsigned int i = 0; i < componentTextList.size(); i++)
	{
		this->window->drawText(componentTextList[i]);
	}
}
