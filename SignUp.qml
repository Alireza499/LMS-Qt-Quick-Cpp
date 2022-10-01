import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    title: qsTr("ثبت نام")

    function validateForm(email)
    {

      var atpos=email.indexOf("@");
      var dotpos=email.lastIndexOf(".");
      if (atpos<1 || dotpos<atpos+2 || dotpos+2>=email.length)
      {
        //Not a valid e-mail address
        return false;
      }
      return true;
    }



    Connections {
        target: MyHandler
        onDaneshjooAdded: {
            text1.color = "#58ae1e"
            text1.text = "شما به عنوان دانشجو ثبت نام کردید لطفا با نام کاربری و رمز عبور خود وارد شوید."
        }
        onOstadAdded: {
            text1.color = "#58ae1e"
            text1.text = "شما به عنوان استاد ثبت نام کردید لطفا با نام کاربری و رمز عبور خود وارد شوید."
        }
        onEmptyInput: {
            text1.color = "#da0808"
            text1.text = "حداقل یکی از ورودی های بالا خالی است. لطفا تمام اطلاعات را وارد کنید"
        }
        onInvalidEmail: {
            text1.color = "#da0808"
            text1.text = "ایمیل شما صحیح نمیباشد"
        }
        onUsedKarbari: {
            text1.color = "#da0808"
            text1.text = "این نام کاربری قبلا استفاده شده است"
        }
    }

    TextArea {
        id: textArea1
        x: 240
        y: 15
        placeholderText: qsTr("نام کاربری")
    }

    TextArea {
        id: textArea2
        x: 240
        y: 66
        visible: true
        placeholderText: qsTr("رمز عبور")
    }

    Button {
        id: button
        x: 268
        y: 264
        text: qsTr("ثبت نام")

        Connections {
            target: button
            onClicked: {
                validateForm(textArea3.text)?
                checkBox.checked ? MyHandler.addOstad(
                                              textArea1.text, textArea3.text,
                                              textArea2.text) : MyHandler.addDaneshjoo(
                                              textArea1.text, textArea3.text,
                                              textArea2.text):MyHandler.invalidEmail()

            }

        }
    }

    Button {
        id: button1
        x: 268
        y: 318
        text: qsTr("بازگشت")

        Connections {
            target: button1
            onClicked: stackView.pop()
        }
    }

    CheckBox {
        id: checkBox
        x: 216
        y: 176
        text: qsTr("ثبت نام به عنوان استاد")
        checked: false
    }

    TextArea {
        id: textArea3
        x: 240
        y: 117
        visible: true
        placeholderText: qsTr("ایمیل")
    }

    Text {
        id: text1
        x: 274
        y: 233
        width: 52
        height: 25
        color: "#da0808"
        text: qsTr("")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignHCenter
    }
}
