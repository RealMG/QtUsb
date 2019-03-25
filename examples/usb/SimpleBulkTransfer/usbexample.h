#ifndef USBEXAMPLE_H
#define USBEXAMPLE_H

#include <QObject>
#include <QUsbDevice>
#include <QUsbTransferHandler>

const QtUsb::Endpoint USB_PIPE_IN = 0x81;   /* Bulk output endpoint for responses */
const QtUsb::Endpoint USB_PIPE_OUT = 0x01;	   /* Bulk input endpoint for commands */
const quint16 USB_TIMEOUT_MSEC = 300;

class UsbExample : public QObject
{
    Q_OBJECT
public:
    explicit UsbExample(QObject *parent = Q_NULLPTR);
    ~UsbExample(void);
    void setupDevice(void);
    bool openDevice(void);
    bool closeDevice(void);
    void read(QByteArray *buf);
    void write(QByteArray *buf);

public slots:
    void onReadComplete(void);
    void onWriteComplete(qint64 bytes);

signals:

public slots:

private:
    QUsbDevice* m_usb_dev;
    QUsbTransferHandler* m_transfer_handler;

    QByteArray m_send, m_recv;

    QtUsb::DeviceFilter m_filter;
    QtUsb::DeviceConfig m_config;

    QtUsb::Endpoint m_read_ep, m_write_ep;
};

#endif // USBEXAMPLE_H
