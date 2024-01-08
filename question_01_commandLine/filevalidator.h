#ifndef FILEVALIDATOR_H
#define FILEVALIDATOR_H

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QString>

class FileValidator {
public:
  FileValidator(QString fName);

  int readValidateA() const;
  int readValidateB() const;
  int readValidateC() const;
  int readValidateD() const;

private:
  QString fileName;
};

#endif // FILEVALIDATOR_H
