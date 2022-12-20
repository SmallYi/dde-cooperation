#ifndef MACHINE_ANDROIDMACHINEDBUSADAPTOR_H
#define MACHINE_ANDROIDMACHINEDBUSADAPTOR_H

#include <QObject>
#include <QDBusConnection>

class AndroidMachine;
class QDBusMessage;

class AndroidMachineDBusAdaptor : public QObject {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.deepin.dde.Cooperation1.Machine.Android")

public:
    AndroidMachineDBusAdaptor(AndroidMachine *machine, QDBusConnection bus, const QString &path);
    ~AndroidMachineDBusAdaptor();

public slots:
    void StartCast(const QDBusMessage &message);

private:
    AndroidMachine *const m_machine;
    QString m_path;
    QDBusConnection m_bus;
};

#endif // !MACHINE_ANDROIDMACHINEDBUSADAPTOR_H
