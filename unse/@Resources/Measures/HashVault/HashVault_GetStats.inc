[Variables]
LeftURL=http://#sitename#/api/miner/
RightURL="/stats"


[MeasureIsIHavePayID]
#��������� �������� �� PayID
UpdateDivider=-1
Measure=String
String=#PayID#
DynamicVariables=1
IfMatch="-"
IfNotMatchAction=[!CommandMeasure MeasurePayIdInput "ExecuteBatch 2"]

[MeasurePayIdInput]
# ������ ����� SUMO Pay Id ����� �����
DynamicVariables=1
Measure=Plugin
Plugin=InputText
X=100
Y=30
W=260
H=90
FontSize=13
FontColor=#valuefontcolor#255
SolidColor=0,0,0,255
AntiAlias=1
FocusDismiss=1
DefaultValue=#PayID#
#������ ���������� �� �� ��� �������
Command1=[!SetVariable PayID "$UserInput$"]
#������ ������ URL c Pay ID ��� �������
Command2=[!SetOption MeasureGetMinerStats URL "#LeftURL##*PayID*##RightURL#"][!UpdateMeter *][!UpdateMeasure *][!Redraw]

[MeasureGetMinerStats]
# ������ ��� (�� �������! �� �� ��������!) ����� �� sumo Pay id
UpdateDivider=30
UpdateRate=1
DynamicVariables=1
Measure=Plugin
Plugin=WebParser
# URL ���� ����� MeasurePayIdInput �� #*PayID*#
RegExp=(?siU)(?(?=.*"hash").*"hash":(.*),"identifier").*"amtPaid":(.*),"amtDue":(.*),"txnCount"
ForceReload=1

[MeasureMinerHashrate]
# ������� �������
Measure=Plugin
Plugin=WebParser
URL=[MeasureGetMinerStats]
StringIndex=1

