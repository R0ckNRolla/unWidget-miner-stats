[MeasureGetLastBlockTimeUnix]
#�������� ����� ���������� �����
UpdateDivider=120
UpdateRate=1
DynamicVariables=1
Measure=Plugin
Plugin=WebParser
URL=https://#sitename#/api/pool/stats
RegExp=(?siU)"lastBlockFoundTime":(.*),"lastBlockFound"
ForceReload=1

[MeasureLastBlockTimeUnix]
# �������� ����� ����� ����� ��������� ���� � unix time stamp 
Measure=Plugin
Plugin=WebParser
URL=[MeasureGetLastBlockTimeUnix]
StringIndex=1