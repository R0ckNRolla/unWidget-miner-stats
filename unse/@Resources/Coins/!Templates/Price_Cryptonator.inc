[MeasureGetBTCPrice]
#�������� ����� sumo �� btc 
UpdateDivider=60
UpdateRate=1
DynamicVariables=1
Measure=Plugin
Plugin=WebParser
URL=https://api.cryptonator.com/api/ticker/sumo-btc
RegExp=(?siU)"price":"(.*)","volume"
ForceReload=1
StringIndex=1

[MeasureBTCPrice]
# �������� sumo to btc ����
Measure=Calc
Formula= MeasureGetBTCPrice

[MeasureUSDPrice]
# �������� sumo to usd ����
Measure=Calc
Formula= MeasureGetBTC_USDPrice * MeasureBTCPrice