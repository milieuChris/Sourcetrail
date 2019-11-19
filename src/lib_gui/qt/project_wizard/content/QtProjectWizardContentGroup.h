#ifndef QT_PROJECT_WIZARD_CONTENT_GROUP_H
#define QT_PROJECT_WIZARD_CONTENT_GROUP_H

#include "QtProjectWizardContent.h"

class QCheckBox;

class QtProjectWizardContentGroup: public QtProjectWizardContent
{
	Q_OBJECT

public:
	QtProjectWizardContentGroup(QtProjectWizardWindow* window);

	void addContent(QtProjectWizardContent* content);
	void addSpace();

	void setIsForm(bool isForm);
	bool hasContents() const;

protected:
	// QtProjectWizardContent implementation
	virtual void populate(QGridLayout* layout, int& row) override;
	void populateForm(QGridLayout* layout, int& row);

	virtual void load() override;
	virtual void save() override;
	virtual bool check() override;

	virtual bool isScrollAble() const override;

private:
	std::vector<QtProjectWizardContent*> m_contents;
	bool m_isForm;
};

#endif	  // QT_PROJECT_WIZARD_CONTENT_GROUP_H
