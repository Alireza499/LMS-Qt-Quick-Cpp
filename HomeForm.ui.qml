import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    title: qsTr("صفحه ورود کاربران")

    Connections {
        target: MyHandler
        onRightPassDanesjoo: stackView.push("AsliDaneshjoo.qml")
        onRightPassOstad: stackView.push("AsliOstad.qml")
        onWrongPass: {
            textArea.text = ""
            textArea1.text = ""
            text1.text = "نام کاربری یا رمز عبور اشتباه است."
        }
    }

    Button {
        id: button
        x: 268
        y: 251
        text: qsTr("تایید")

        Connections {
            target: button
            onClicked: MyHandler.checkUserPass(textArea.text, textArea1.text)
        }
    }

    TextArea {
        id: textArea
        x: 240
        y: 83
        hoverEnabled: false
        placeholderText: qsTr("نام کاربری")
    }

    TextField {
        id: textArea1
        x: 240
        y: 165
        placeholderText: qsTr("رمز عبور")
        echoMode: TextInput.Password
    }

    Button {
        id: button1
        x: 153
        y: 337
        width: 295
        height: 30
        text: qsTr("ثبت نام")

        Connections {
            target: button1
            onClicked: stackView.push("SignUp.qml")
        }
    }

    Text {
        id: text1
        x: 240
        y: 221
        width: 120
        height: 14
        color: "#da0808"
        text: qsTr("")
        font.pixelSize: 12
    }


}
