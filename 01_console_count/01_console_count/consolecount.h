#ifndef CONSOLECOUNT_H
#define CONSOLECOUNT_H

#include <QRegularExpression>
#include <QStringList>

class ConsoleCount {
public:
  ConsoleCount();
  ConsoleCount(QStringList args);
  QString doCount();

private:
  bool aFlag, bFlag, cFlag, dFlag;
  QStringList fileNames;
  QRegularExpression removeStr;

  QString processFile(QString f);
  QString process(char flag, QString contents);
};

#endif // CONSOLECOUNT_H
