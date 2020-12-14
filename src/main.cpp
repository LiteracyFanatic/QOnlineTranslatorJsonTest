#include <QDebug>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QOnlineTranslator>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QOnlineTranslator translator;
    translator.translate(argv[1], QOnlineTranslator::Google);
    QObject::connect(&translator, &QOnlineTranslator::finished, [&] {
        if (translator.error() == QOnlineTranslator::NoError)
        {
            QJsonDocument doc = translator.toJson();
            qInfo().noquote() << QString(doc.toJson(QJsonDocument::Indented));
            exit(0);
        }
        else
        {
            qCritical() << translator.errorString();
            exit(1);
        }
    });

    return QCoreApplication::exec();
}
