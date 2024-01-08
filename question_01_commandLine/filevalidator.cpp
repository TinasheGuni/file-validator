#include "filevalidator.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>

FileValidator::FileValidator(QString fName) : fileName(fName) {}

int FileValidator::readValidateA() const {
  QFile inFile(fileName);
  int count = 0;

  if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qCritical() << inFile.errorString();
  } else {

    QTextStream inStream(&inFile);

    while (!inStream.atEnd()) {
      QString data = inStream.readLine();

      QRegularExpression regex("(\[A-Z][A-Za-z]{3,})");
      QRegularExpressionMatchIterator i = regex.globalMatch(data);

      QStringList words;
      while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString word = match.captured(1);
        words << word;
        //        qInfo() << word;
        count++;
      }
    }
    qInfo() << "The Number of words longer than 4 characters, that start "
               "with a capital letter:"
            << count;

    inFile.close();
  }
  return count;
}

int FileValidator::readValidateB() const {
  QFile inFile(fileName);
  int count = 0;

  if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qCritical() << inFile.errorString();
  } else {

    QTextStream inStream(&inFile);

    while (!inStream.atEnd()) {
      QString data = inStream.readLine();

      QRegularExpression regex("(\\b([^-]\\w+-\\w+-?)+)\\b");
      QRegularExpressionMatchIterator i = regex.globalMatch(data);

      QStringList words;
      while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString word = match.captured(1);
        words << word;
        //        qInfo() << word;
        count++;
      }
    }
    qInfo() << "The Number of words that are hyphenated :" << count;

    inFile.close();
  }
  return count;
}

int FileValidator::readValidateC() const {
  QFile inFile(fileName);
  int count = 0;

  if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qCritical() << inFile.errorString();
  } else {
    QTextStream inStream(&inFile);

    while (!inStream.atEnd()) {
      QString data = inStream.readLine();

      QRegularExpression regex("(([\\w+])\\w+([\\w+]\\1))");
      QRegularExpressionMatchIterator i = regex.globalMatch(data);

      QStringList words;
      while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString word = match.captured(1);
        words << word;
        //        qInfo() << word;
        count++;
      }
    }
    qDebug() << "The Number of words that start and end with the same "
                "character"
             << count;

    inFile.close();
  }
  return count;
}

int FileValidator::readValidateD() const {
  QFile inFile(fileName);
  int count = 0;

  if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qCritical() << inFile.errorString();
  } else {

    QTextStream inStream(&inFile);

    while (!inStream.atEnd()) {
      QString data = inStream.readLine();

      QRegularExpression regex("((\\b[^aeiou]\\w+\\b))",
                               QRegularExpression::CaseInsensitiveOption);
      QRegularExpressionMatchIterator i = regex.globalMatch(data);

      QStringList words;
      while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString word = match.captured(1);
        words << word;
        //        qInfo() << word;
        count++;
      }
    }
    qDebug() << "The Number of words that do not start with a vowel" << count;

    inFile.close();
  }
  return count;
}
