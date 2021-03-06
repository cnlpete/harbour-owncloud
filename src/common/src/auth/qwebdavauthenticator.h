#ifndef QWEBDAVAUTHENTICATOR_H
#define QWEBDAVAUTHENTICATOR_H

#include <QObject>
#include "authenticator.h"

#include <settings/nextcloudsettingsbase.h>
#include <qwebdav.h>
#include <qwebdavdirparser.h>

class QWebDavAuthenticator : public Authenticator
{
    Q_OBJECT

public:
    explicit QWebDavAuthenticator(QObject *parent = Q_NULLPTR,
                                  AccountBase* settings = Q_NULLPTR);

public slots:
    void authenticate() Q_DECL_OVERRIDE;
    void abort() Q_DECL_OVERRIDE;

protected:
    void updateClientSettings() Q_DECL_OVERRIDE;

private:
    void sslErrorOccured(const QList<QSslError> &errors);
    void testConnectionFinished(QNetworkReply* reply);

    QWebdav* m_client = Q_NULLPTR;
    QWebdavDirParser m_dirParser;

};
Q_DECLARE_METATYPE(QWebDavAuthenticator*)

#endif // QWEBDAVAUTHENTICATOR_H
