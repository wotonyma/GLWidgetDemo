import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.3

//此功能实现图片的平移和定点缩放
ApplicationWindow{
        title:qsTr("Hello Image");
        width:600; height:600;
        visible: true

        Flickable{
             id:flickView;
             anchors.fill: parent
             contentWidth: 600
             contentHeight: 600

             Image{
                 id:img;
                 width:parent.width;
                 height:parent.height;
                 anchors.centerIn: parent;
                 fillMode: Image.PreserveAspectFit;
                 source:"file:///d:/test/copy/ori_mark.jpg";
             }
             MouseArea{
                anchors.fill: parent
                onWheel:{
                    if(wheel.angleDelta.y>0){
                        flickView.contentWidth = flickView.contentWidth*1.2
                        flickView.contentHeight = flickView.contentHeight*1.2
                        flickView.contentX = flickView.contentX+0.2*wheel.x
                        flickView.contentY = flickView.contentY+0.2*wheel.y
 
                    }
                    else{
                        var newWidth = flickView.contentWidth*0.8
                        if(newWidth>flickView.width){//判断缩放后的contentWidth是否会小于Flickable的width
                            flickView.contentWidth = newWidth
                            flickView.contentX = flickView.contentX-0.2*wheel.x
                            if(flickView.contentX<0){//如果此时内容已经到达边界，则不继续移动
                                flickView.contentX=0
                            }
                        }
                        var newHeight = flickView.contentHeight*0.8
                        if(newHeight>flickView.height){
                            flickView.contentHeight = newHeight
                            flickView.contentY = flickView.contentY-0.2*wheel.y
                            if(flickView.contentY<0){
                                flickView.contentY=0
                            }
                        }
                    }
                }
             }
        }
}

