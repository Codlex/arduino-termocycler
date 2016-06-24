grep -Eo "(.*)(ColdBath)(.*)" DEBUG2.LOG  | sed "s/\[DEBUG\] ColdBathStatus(/,/g" | cut -d "(" -f2 | cut -d ")" -f1 | sed "s/temp1=//g" | sed "s/temp2=//g" | sed "s/level=//g"
