import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick 2.9
import QtQuick.Layouts 1.3
import Azmoonha 1.0
Page {
    width: 600
    height: 400

    title: qsTr("Page 2")

    Frame {
        id: frame
        x: 75
        y: 40
        width: 451
        height: 320

        ScrollView {
            id: scrollView
            x: -12
            y: -12
            width: 451
            height: 320

            ListView {
                id: listView
                x: 0
                y: 0
                width: 451
                height: 320
                delegate: RowLayout {
                    x: 5
                    width: 80
                    height: 40

                    Button
                    {
                        id : azmonbutum
                        width: frame.width
                        text: "111"
                    }

                }
                model: AzmoonModel {
                    list: azmoonList

                }
            }
        }
    }
}
