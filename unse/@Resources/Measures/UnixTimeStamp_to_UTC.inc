[MeasureCurrentTimeStampUTC0]
# ������ �������� �������� ����� � unix time stamp � ��������� �� utc-0 (�.�. ��� ������ ��������� ���� � ���-0)
Measure=Time
TimeZone=0

[MeasureLastBlockTimeAgo]
# �� ���������� ���������� �������� ��������� ���� ���������� ����� � ������ � ������� �:�:�
Measure=Time
TimeStamp=([MeasureCurrentTimeStampUTC0:]-[MeasureLastBlockTimeUnix])
Format=%H:%M:%S
DynamicVariables=1