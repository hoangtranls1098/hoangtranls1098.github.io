import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

//    ComboBox {
//        id: comboBox
//        x: 188
//        y: 195
//        editable: true
//        model: {
//            id : model
//            ListElement {text : "banana"}
//            ListElement {text : "apple"}
//            ListElement {text : "coconut"}

//        }
//        onAccepted: {
//            if(find(editText) === -1)
//                model.append({text: editText})
//        }

//    }

}
