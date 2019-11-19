#ifndef QT_PROJECT_WIZARD_CONTENT_H
#define QT_PROJECT_WIZARD_CONTENT_H

#include <QGridLayout>
#include <QLabel>
#include <QToolButton>
#include <QWidget>

#include "FilePath.h"
#include "QtHelpButton.h"
#include "QtProjectWizardWindow.h"
#include "QtThreadedFunctor.h"

class QtTextEditDialog;

class QtProjectWizardContent: public QWidget
{
	Q_OBJECT

public:
	QtProjectWizardContent(QtProjectWizardWindow* window);

	virtual void populate(QGridLayout* layout, int& row);
	virtual void windowReady();

	virtual void load();
	virtual void save();
	virtual bool check();

	virtual bool isScrollAble() const;

	virtual std::vector<FilePath> getFilePaths() const;
	virtual QString getFileNamesTitle() const;
	virtual QString getFileNamesDescription() const;

	bool isInForm() const;
	void setIsInForm(bool isInForm);

protected:
	QLabel* createFormLabel(QString name) const;
	QLabel* createFormTitle(QString name) const;
	QToolButton* createSourceGroupButton(QString name, QString iconPath) const;

	QtHelpButton* addHelpButton(
		const QString& helpTitle, const QString& helpText, QGridLayout* layout, int row) const;
	QPushButton* addFilesButton(QString name, QGridLayout* layout, int row) const;
	QFrame* addSeparator(QGridLayout* layout, int row) const;

	QtProjectWizardWindow* m_window;

	std::shared_ptr<QtTextEditDialog> m_filesDialog;

protected slots:
	void filesButtonClicked();
	void closedFilesDialog();

private:
	void showFilesDialog(const std::vector<FilePath>& filePaths);

	bool m_isInForm;
	QtThreadedFunctor<const std::vector<FilePath>&> m_showFilesFunctor;
};

#endif	  // QT_PROJECT_WIZARD_CONTENT_H
