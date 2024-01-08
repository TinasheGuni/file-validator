#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>
#include <QStringList>

#include "filevalidator.h"

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);
  QCoreApplication::setApplicationName("Regex Validator");
  QCoreApplication::setApplicationVersion("1.0");

  QCommandLineParser parser;
  parser.addHelpOption();
  parser.addVersionOption();

  //  read contents of the first file
  for (int i = 0; i < argc; i++) {
    if (QCoreApplication::arguments().at(i) == QLatin1String("file1.txt")) {
      qDebug() << "***file1.txt***";

      //      -a flag
      for (int a = 0; a < argc; a++) {
        if (QCoreApplication::arguments().at(a) == QLatin1String("-a")) {

          FileValidator fv("file1.txt");
          fv.readValidateA();
        }
      }

      //      -b flag
      for (int b = 0; b < argc; b++) {
        if (QCoreApplication::arguments().at(b) == QLatin1String("-b")) {
          FileValidator fv("file1.txt");
          fv.readValidateB();
        }
      }

      //      -c flag
      for (int c = 0; c < argc; c++) {
        if (QCoreApplication::arguments().at(c) == QLatin1String("-c")) {
          FileValidator fv("file1.txt");
          fv.readValidateC();
        }
      }

      //      -d flag
      for (int d = 0; d < argc; d++) {
        if (QCoreApplication::arguments().at(d) == QLatin1String("-d")) {
          FileValidator fv("file1.txt");
          fv.readValidateD();
        }
      }
    }
  }

  // read the contents of the second file
  for (int i = 0; i < argc; i++) {
    if (QCoreApplication::arguments().at(i) == QLatin1String("file2.txt")) {
      qDebug() << "\n***file2.txt***";

      //      -a flag
      for (int a = 0; a < argc; a++) {
        if (QCoreApplication::arguments().at(a) == QLatin1String("-a")) {

          FileValidator fv("file2.txt");
          fv.readValidateA();
        }
      }

      //      -b flag
      for (int b = 0; b < argc; b++) {
        if (QCoreApplication::arguments().at(b) == QLatin1String("-b")) {
          FileValidator fv("file2.txt");
          fv.readValidateB();
        }
      }

      //      -c flag
      for (int c = 0; c < argc; c++) {
        if (QCoreApplication::arguments().at(c) == "-c") {
          FileValidator fv("file2.txt");
          fv.readValidateC();
        }
      }

      //      -d flag
      for (int d = 0; d < argc; d++) {
        if (QCoreApplication::arguments().at(d) == "-d") {
          FileValidator fv("file2.txt");
          fv.readValidateD();
        }
      }
    }
  }

  parser.process(app);

  //  error handling if not arguments are entered
  const QStringList args = parser.positionalArguments();
  if (args.count() < 1) {
    qDebug() << "Enter at least one command line argument \n count \n count "
                "file1.txt \n count file1.txt file2.txt \n count -a -b "
                "file1.txt file2.txt \n behaviour \n count -ab -c file1.txt\n";
  }

  return app.exec();
}
