import QtQuick 2.1
import QtQuick.Window 2.0

Window {
    id: page
    visible: true
    width: 500
    height: 500
    color: "#343434"

    Image {
        id: icon
        x: 10
        y: 20
        width: 64
        height: 64
        sourceSize.height: 64
        sourceSize.width: 64
        source: "as.png"
        MouseArea {
                    anchors.fill: parent
                    drag.target: icon
                    drag.axis: Drag.XAndYAxis
                    drag.minimumX: 0
                    drag.maximumX: page.width - icon.width
                    drag.minimumY: 0
                    drag.maximumY: page.height - icon.height
                }
    }

    Rectangle {
        id: cuadro
        width: 250
        height: 480
        color: "white"
        radius: 6
        z: -1
        opacity: 1
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        border.color: "#808080"

        MouseArea {
            id: mouseArea1
            anchors.fill: parent
        }
    }

}
