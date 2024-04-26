import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

Window {
    id: window
    visible: true //表示部件可见
    width: 640
    height: 480
    property alias button_0X: button_0.x
    title: qsTr("Hello World")



    RowLayout {
        id: layout
        anchors.fill: parent
        spacing: 10
        Rectangle {
            color: 'teal'
            Layout.fillWidth: true //尽可能填充宽度
            Layout.minimumWidth: 50
            Layout.preferredWidth: 100
            Layout.maximumWidth: 300
            Layout.minimumHeight: 150
            Text {
                anchors.centerIn: parent
                text: parent.width + 'x' + parent.height
            }
        }
        Rectangle {
            color: 'plum'
            Layout.fillWidth: true
            Layout.minimumWidth: 100
            Layout.preferredWidth: 200
            Layout.preferredHeight: 100
            Text {
                anchors.centerIn: parent
                text: parent.width + 'x' + parent.height
            }
        }

        Button {
            id: button_0
            width: 75
            height: 26
            text: qsTr("qt btn")
            anchors.verticalCenterOffset: 0
            anchors.verticalCenter: parent.verticalCenter
            transformOrigin: Item.Center
        }
    }

}


/*##^##
Designer {
    D{i:6;anchors_height:26;anchors_width:75;anchors_x:218;anchors_y:162}
}
##^##*/
