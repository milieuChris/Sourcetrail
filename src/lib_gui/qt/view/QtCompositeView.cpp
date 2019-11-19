#include "QtCompositeView.h"

#include <QBoxLayout>

#include "ColorScheme.h"
#include "QtViewWidgetWrapper.h"
#include "utilityQt.h"

QtCompositeView::QtCompositeView(
	ViewLayout* viewLayout, CompositeDirection direction, const std::string& name)
	: CompositeView(viewLayout, direction, name)
{
	QBoxLayout* layout;
	if (getDirection() == CompositeView::DIRECTION_HORIZONTAL)
	{
		layout = new QHBoxLayout();
	}
	else
	{
		layout = new QVBoxLayout();
	}

	layout->setSpacing(5);
	layout->setContentsMargins(8, 8, 8, 8);
	layout->setAlignment(Qt::AlignTop);

	m_widget = new QWidget();
	m_widget->setLayout(layout);

	refreshView();
}

void QtCompositeView::createWidgetWrapper()
{
	setWidgetWrapper(std::make_shared<QtViewWidgetWrapper>(m_widget));
}

void QtCompositeView::refreshView()
{
	m_onQtThread([=]() {
		utility::setWidgetBackgroundColor(
			m_widget, ColorScheme::getInstance()->getColor("search/background"));
	});
}

void QtCompositeView::addViewWidget(View* view)
{
	m_widget->layout()->addWidget(QtViewWidgetWrapper::getWidgetOfView(view));
}
