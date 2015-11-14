#include "commonpage.h"
#include "ui_commonpage.h"
#include <QSpacerItem>

CommonPage::CommonPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommonPage)
{
    ui->setupUi(this);

    initWidget();
    //disableWidget();

}

CommonPage::~CommonPage()
{
    delete ui;
}

void CommonPage::initWidget()
{

        le_model = new QLineEdit();
        le_model->setToolTip("有ota功能不能带空格");
        le_model->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        le_bt_name = new QLineEdit();
        le_bt_name->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        le_homepage = new QLineEdit();
        le_homepage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        le_sleep_time = new QLineEdit();
        le_sleep_time->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);


        le_bright_level = new QLineEdit();
        le_bright_level->setToolTip("0~255");
        le_bright_level->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        le_displayId = new QLineEdit();
        le_displayId->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
       // cb_language = new QComboBox();
      //  QList<QString> language_list;
       // language_list << "中文简体" << "英语" << "西班牙语";
       // QStringList strList =  QStringList(language_list);
      //  cb_language->addItems(strList);
      //  cb_language->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        le_language = new QLineEdit();
        le_language->setToolTip("persist.sys.language=");
        le_language->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        le_country = new QLineEdit();
        le_country->setToolTip("persist.sys.country=");
        le_country->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

        btn_languageList = new QPushButton("显示支持语言列表");
        cb_wifi_state = new QComboBox();
        cb_wifi_state->addItem("关");
        cb_wifi_state->addItem("开");
        cb_wifi_state->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        cb_bt_state = new QComboBox();
        cb_bt_state->addItem("关");
        cb_bt_state->addItem("开");
       cb_bt_state->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        //cb_timezone = new QComboBox();
       // cb_timezone->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        le_timezone = new QLineEdit();
        le_timezone->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

        le_timezone->setToolTip("百度城市英文名,\n在时区列表文件中搜索相应的值");
        btn_timezoneList = new QPushButton("支持时区列表");
        cb_date_format = new QComboBox();
        cb_date_format->addItem("24");
        cb_date_format->addItem("12");
        cb_date_format->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        cb_volume = new QComboBox();
        cb_volume->addItem("50%");
        cb_volume->addItem("60%");
        cb_volume->addItem("70%");
        cb_volume->addItem("80%");
        cb_volume->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        cb_install_non_market = new QComboBox();
        cb_install_non_market->addItem("关");
        cb_install_non_market->addItem("开");
        cb_install_non_market->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        cb_adb_state = new QComboBox();
        cb_adb_state->addItem("关");
        cb_adb_state->addItem("开");
        cb_adb_state->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        cb_screenshot_btn = new QComboBox();
        cb_screenshot_btn->addItem("关");
        cb_screenshot_btn->addItem("开");
        cb_screenshot_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);



        lbl_model = new QLabel(tr("设备型号:"));
        lbl_model->setToolTip("有ota功能不能带空格");
        lbl_bt_name = new QLabel(tr("蓝牙名:"));
        lbl_homepage = new QLabel(tr("浏览器主页:"));
        lbl_sleep_time = new QLabel(tr("屏幕待机:"));
        lbl_sleep_time->setToolTip("6000,12000");
        lbl_bright_level = new QLabel(tr("默认亮度:"));
        lbl_bright_level->setToolTip("0~255");
        lbl_language = new QLabel(tr("默认语言:"));
        lbl_displayId = new QLabel(tr("版本号:"));
        lbl_timezone = new QLabel(tr("时区:"));
        lbl_timezone->setToolTip("百度城市英文名,\n在时区列表文件中搜索相应的值");
        lbl_date_format = new QLabel(tr("时间格式:"));
        lbl_volume = new QLabel(tr("默认音量:"));
        lbl_wifi_state = new QLabel(tr("默认wifi:"));
        lbl_bt_state = new QLabel(tr("默认蓝牙:"));
        lbl_install_non_market = new QLabel(tr("未知来源安装:"));
        lbl_adb_state = new QLabel(tr("adb调试模式:"));
        lbl_screenshot_btn = new QLabel(tr("截图按钮:"));

        common_page_scrollArea = new QScrollArea();
        common_page_scrollArea->setWidgetResizable(true);
       common_scrollWidget = new QWidget(common_page_scrollArea);
       common_page_scrollArea->setWidget(common_scrollWidget);
        QGridLayout *common_scrollLayout = new QGridLayout(common_scrollWidget);

        common_scrollLayout->addWidget(lbl_model, 0, 0);
        common_scrollLayout->addWidget(le_model, 0, 1);
        common_scrollLayout->addWidget(lbl_bt_name, 1, 0);
        common_scrollLayout->addWidget(le_bt_name, 1, 1);
        common_scrollLayout->addWidget(lbl_homepage, 2, 0);
        common_scrollLayout->addWidget(le_homepage, 2, 1);

        common_scrollLayout->addWidget(lbl_sleep_time, 3, 0);
        common_scrollLayout->addWidget(le_sleep_time, 3, 1);
        common_scrollLayout->addWidget(lbl_displayId, 4, 0);
        common_scrollLayout->addWidget(le_displayId, 4, 1);
        common_scrollLayout->addWidget(lbl_language, 5, 0);
        common_scrollLayout->addWidget(le_language, 5, 1);
        common_scrollLayout->addWidget(le_country, 5, 2);
        common_scrollLayout->addWidget(btn_languageList, 5, 3);
        common_scrollLayout->addWidget(lbl_displayId, 6, 0);
        common_scrollLayout->addWidget(le_displayId, 6, 1);
        common_scrollLayout->addWidget(lbl_wifi_state, 7, 0);
        common_scrollLayout->addWidget(cb_wifi_state, 7, 1);
        common_scrollLayout->addWidget(lbl_bt_state, 8, 0);
        common_scrollLayout->addWidget(cb_bt_state, 8, 1);
        common_scrollLayout->addWidget(lbl_timezone, 9, 0);
        common_scrollLayout->addWidget(le_timezone, 9, 1);
        common_scrollLayout->addWidget(btn_timezoneList, 9, 2);
        //common_scrollLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Expanding), 9, 3);
        common_scrollLayout->addWidget(lbl_date_format, 10, 0);
        common_scrollLayout->addWidget(cb_date_format, 10, 1);
        common_scrollLayout->addWidget(lbl_volume, 11, 0);
        common_scrollLayout->addWidget(cb_volume, 11, 1);
        common_scrollLayout->addWidget(lbl_adb_state, 12, 0);
        common_scrollLayout->addWidget(cb_adb_state, 12, 1);
        common_scrollLayout->addWidget(lbl_screenshot_btn, 13, 0);
        common_scrollLayout->addWidget(cb_screenshot_btn, 13, 1);

       // common_scrollLayout->setColumnStretch(2,-1);
        common_scrollLayout->setSpacing(15);

        QVBoxLayout *common_page_layout = new QVBoxLayout(this);
        common_page_layout->addWidget(common_page_scrollArea);


}

void CommonPage::disableWidget()
{
    QList<QObject *> list = common_scrollWidget->children();
    QWidget *w;
    for(int i = 1; i < list.count(); i++)
    {
        w = qobject_cast<QWidget *>(list.at(i));
        w->setDisabled(true);
    }
}

void CommonPage::enableWidget()
{
    QList<QObject *> list = common_scrollWidget->children();
    QWidget *w;
    for(int i = 1; i < list.count(); i++)
    {
        w = qobject_cast<QWidget *>(list.at(i));
        w->setEnabled(true);
    }
}

void CommonPage::loadCfg()
{
    enableWidget();
    QString versionMk = Global::srcPath + "/" + Global::devicePath + "/version_id.mk";
    QString boardCfg = Global::srcPath + "/" + Global::devicePath + "/BoardConfig.mk";
    QString sofiaMk = Global::srcPath + "/" + Global::devicePath + "/sofia3gr.mk";
    QString sysProp = Global::srcPath +  "/" + Global::devicePath + "/system.prop";
    QString defSettingProvider = Global::srcPath + "/" + Global::settingproviderPath + "/res/values/defaults.xml";
    le_model->setText(textHelper.readTextStr(sysProp, "ro.product.model", "prop"));
    le_bt_name->setText(textHelper.readTextStr(sysProp, "rw.bt.name.wh", "prop"));
    le_homepage->setText(textHelper.readTextStr(sysProp, "ro.homepage_base.wb", "prop"));
    le_sleep_time->setText(textHelper.readTextStr(sysProp, "ro.defsleeptime.wb", "prop"));
    le_homepage->setText(textHelper.readTextStr(sysProp, "ro.homepage_base.wb", "prop"));
    le_displayId->setText(textHelper.readTextStr(versionMk, "Settings_Build_Number", "prop"));
    le_language->setText(textHelper.readTextStr(sysProp,"persist.sys.language", "prop"));
    le_country->setText(textHelper.readTextStr(sysProp, "persist.sys.country", "prop"));
    le_timezone->setText(textHelper.readTextStr(sysProp, "persist.sys.timezone", "prop"));
    cb_wifi_state->setCurrentIndex((textHelper.readTextStr(defSettingProvider, "def_wifi_on", "xml").compare("false") ? 1:0));
    //cb_bt_state->setCurrentIndex((textHelper.readTextStr(defSettingProvider, "def_bluetooth_on", "xml").compare("false") ? 1:0));
    cb_adb_state->setCurrentIndex((textHelper.readTextStr(sofiaMk, "persist.sys.usb.config", "mk")).contains("adb") ? 1:0);
    cb_screenshot_btn->setCurrentIndex((textHelper.readTextStr(defSettingProvider, "def_screenshot_button_show", "xml").compare("false") ? 1:0));
}
