import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
Item {
    id: name1
    width: 480
    height: 480


    ListView {
        implicitHeight: 250
        implicitWidth: 250
        clip: true
        model: model123
        delegate:
            Rectangle{
            border.color: "black"
            border.width: 2
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            height: 50
            Text {
                id: name3
                text: model.type + "   " + model.size
                anchors.centerIn: parent

            }
        }

    }
}
