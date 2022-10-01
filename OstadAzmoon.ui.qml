import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    title: qsTr("وارد کردن سوالات در آزمون")

    Connections {
        target: MyHandler
        onPyanAzmoon: stackView.push("AzmoonEzafeShod.ui.qml")
        onNextsoual: {
            textArea.text = ""
            textArea1.text = ""
            textArea2.text = ""
            textArea3.text = ""
            textField.text = ""
            textField1.text = ""
        }
    }

    Button {
        id: button
        x: 270
        y: 352
        text: qsTr("تایید و پابان سوال ها")

        Connections {
            target: button
            onClicked: MyHandler.taeedVaPyanAzmoon(textField2)
        }
    }

    TextArea {
        id: textArea
        x: 150
        y: 128
        width: 368
        height: 45
        placeholderText: qsTr("گزینه اول")
    }

    TextArea {
        id: textArea1
        x: 150
        y: 164
        width: 368
        height: 45
        placeholderText: qsTr("گزینه دوم")
    }

    TextArea {
        id: textArea2
        x: 150
        y: 198
        width: 368
        height: 45
        placeholderText: qsTr("گزینه سوم")
    }

    TextArea {
        id: textArea3
        x: 150
        y: 232
        width: 368
        height: 45
        placeholderText: qsTr("گزینه چهارم")
    }

    TextField {
        id: textField
        x: 37
        y: 30
        width: 543
        height: 78
        horizontalAlignment: Text.AlignRight
        placeholderText: qsTr("صورت سوال")
    }

    TextField {
        id: textField1
        x: 398
        y: 301
        placeholderText: qsTr("عدد گزینه درست")
        validator: IntValidator {
            bottom: 1
            top: 4
        }
    }

    Button {
        id: button1
        x: 448
        y: 351
        text: qsTr("سوال بعدی")

        Connections {
            target: button1
            onClicked: MyHandler.nextSoual(textField.text, textArea.text,
                                           textArea1.text, textArea2.text,
                                           textArea3.text, textField1.text)
        }
    }

    TextField {
        id: textField2
        x: 29
        y: 353
        width: 136
        height: 44
        placeholderText: qsTr("زمان آزمون به دقیقه")
        validator: IntValidator {
            top: 120
            bottom: 1
        }
    }
}
