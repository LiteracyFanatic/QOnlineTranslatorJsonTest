#include <QDebug>
#include <QCoreApplication>
#include <QOnlineTranslator>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QOnlineTranslator translator;
    translator.translate("Hello world", QOnlineTranslator::Google);
    QObject::connect(&translator, &QOnlineTranslator::finished, [&] {
        if (translator.error() == QOnlineTranslator::NoError)
            qInfo() << translator.translation();
        else
            qCritical() << translator.errorString();
    });

    return QCoreApplication::exec();
}
