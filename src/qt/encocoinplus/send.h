// Copyright (c) 2019-2020 The PIVX developers
// Copyright (c) 2022 The EncocoinPlus developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SEND_H
#define SEND_H

#include <QWidget>
#include <QPushButton>

#include "qt/encocoinplus/pwidget.h"
#include "qt/encocoinplus/contactsdropdown.h"
#include "qt/encocoinplus/sendmultirow.h"
#include "qt/encocoinplus/sendcustomfeedialog.h"
#include "walletmodel.h"
#include "coincontroldialog.h"
#include "qt/encocoinplus/tooltipmenu.h"

//static const int MAX_SEND_POPUP_ENTRIES = 8;

class encocoinplusGUI;
class ClientModel;
class WalletModel;
class WalletModelTransaction;

namespace Ui {
class send;
class QPushButton;
}

class SendWidget : public PWidget
{
    Q_OBJECT

public:
    explicit SendWidget(encocoinplusGUI* parent);
    ~SendWidget();

    void addEntry();

    void loadClientModel() override;
    void loadWalletModel() override;

Q_SIGNALS:
    /** Signal raised when a URI was entered or dragged to the GUI */
    void receivedURI(const QString& uri);

public Q_SLOTS:
    void onChangeAddressClicked();
    void onChangeCustomFeeClicked();
    void onCoinControlClicked();
    void onOpenUriClicked();
    void onValueChanged();
    void refreshAmounts();
    void changeTheme(bool isLightTheme, QString &theme) override;

protected:
    void resizeEvent(QResizeEvent *event) override;
    void showEvent(QShowEvent *event) override;

private Q_SLOTS:
    void onSendClicked();
    void onContactsClicked(SendMultiRow* entry);
    void onMenuClicked(SendMultiRow* entry);
    void onAddEntryClicked();
    void clearEntries();
    void clearAll(bool fClearSettings = true);
    void onCheckBoxChanged();
    void onContactMultiClicked();
    void onDeleteClicked();
    void onResetCustomOptions(bool fRefreshAmounts);
    void onResetSettings();

private:
    Ui::send *ui;
    QPushButton *coinIcon;
    QPushButton *btnContacts;

    SendCustomFeeDialog* customFeeDialog = nullptr;
    bool isCustomFeeSelected = false;
    bool fDelegationsChecked = false;
    CAmount cachedDelegatedBalance{0};

    int nDisplayUnit;
    QList<SendMultiRow*> entries;
    CoinControlDialog *coinControlDialog = nullptr;

    ContactsDropdown *menuContacts = nullptr;
    TooltipMenu *menu = nullptr;
    // Current focus entry
    SendMultiRow* focusedEntry = nullptr;

    void resizeMenu();
    QString recipientsToString(QList<SendCoinsRecipient> recipients);
    SendMultiRow* createEntry();
    bool send(QList<SendCoinsRecipient> recipients);
    void setFocusOnLastEntry();
    void showHideCheckBoxDelegations();
    void updateEntryLabels(QList<SendCoinsRecipient> recipients);
    void setCustomFeeSelected(bool isSelected, const CAmount& customFee = DEFAULT_TRANSACTION_FEE);
    void setCoinControlPayAmounts();
};

#endif // SEND_H
