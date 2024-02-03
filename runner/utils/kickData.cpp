#include "kickData.h"

json kickData = json::parse(R"({
			"SRS" : {"kicks" : {"10" : [ [ 1, 0 ], [ 1, 1 ], [ 0, -2 ], [ 1, -2 ] ], "12" : [ [ 1, 0 ], [ 1, 1 ], [ 0, -2 ], [ 1, -2 ] ], "13" : [ [ 1, 0 ], [ 1, -2 ], [ 1, -1 ], [ 0, -2 ], [ 0, -1 ] ], "20" : [ [ 0, 1 ], [ -1, 1 ], [ 1, 1 ], [ -1, 0 ], [ 1, 0 ] ], "21" : [ [ -1, 0 ], [ -1, -1 ], [ 0, 2 ], [ -1, 2 ] ], "23" : [ [ 1, 0 ], [ 1, -1 ], [ 0, 2 ], [ 1, 2 ] ], "30" : [ [ -1, 0 ], [ -1, 1 ], [ 0, -2 ], [ -1, -2 ] ], "31" : [ [ -1, 0 ], [ -1, -2 ], [ -1, -1 ], [ 0, -2 ], [ 0, -1 ] ], "32" : [ [ -1, 0 ], [ -1, 1 ], [ 0, -2 ], [ -1, -2 ] ], "01" : [ [ -1, 0 ], [ -1, -1 ], [ 0, 2 ], [ -1, 2 ] ], "03" : [ [ 1, 0 ], [ 1, -1 ], [ 0, 2 ], [ 1, 2 ] ], "02" : [ [ 0, -1 ], [ 1, -1 ], [ -1, -1 ], [ 1, 0 ], [ -1, 0 ] ]}, "i_kicks" : {"10" : [ [ 2, 0 ], [ -1, 0 ], [ 2, -1 ], [ -1, 2 ] ], "12" : [ [ -1, 0 ], [ 2, 0 ], [ -1, -2 ], [ 2, 1 ] ], "13" : [], "20" : [], "21" : [ [ 1, 0 ], [ -2, 0 ], [ 1, 2 ], [ -2, -1 ] ], "23" : [ [ 2, 0 ], [ -1, 0 ], [ 2, -1 ], [ -1, 2 ] ], "30" : [ [ 1, 0 ], [ -2, 0 ], [ 1, 2 ], [ -2, -1 ] ], "31" : [], "32" : [ [ -2, 0 ], [ 1, 0 ], [ -2, 1 ], [ 1, -2 ] ], "01" : [ [ -2, 0 ], [ 1, 0 ], [ -2, 1 ], [ 1, -2 ] ], "03" : [ [ -1, 0 ], [ 2, 0 ], [ -1, -2 ], [ 2, 1 ] ], "02" : []}, "i2_kicks" : {"10" : [ [ 0, 1 ], [ 1, 0 ], [ 1, 1 ] ], "12" : [ [ 1, 0 ], [ 0, -1 ], [ 1, 0 ] ], "13" : [], "20" : [], "21" : [ [ -1, 0 ], [ 0, 1 ], [ -1, 0 ] ], "23" : [ [ 0, 1 ], [ 1, 0 ], [ 1, -1 ] ], "30" : [ [ -1, 0 ], [ 0, 1 ], [ -1, 2 ] ], "31" : [], "32" : [ [ 0, -1 ], [ -1, 0 ], [ -1, 1 ] ], "01" : [ [ 0, -1 ], [ -1, 0 ], [ -1, -1 ] ], "03" : [ [ 1, 0 ], [ 0, -1 ], [ 1, -2 ] ], "02" : []}, "i3_kicks" : {"10" : [ [ -1, 0 ], [ 1, 0 ], [ 0, -1 ], [ 0, 1 ] ], "12" : [ [ 1, 0 ], [ -1, 0 ], [ 0, -2 ], [ 0, 2 ] ], "13" : [], "20" : [], "21" : [ [ -1, 0 ], [ 1, 0 ], [ 0, 2 ], [ 0, -2 ] ], "23" : [ [ -1, 0 ], [ 1, 0 ], [ 0, 1 ], [ 0, -1 ] ], "30" : [ [ -1, 0 ], [ 1, 0 ], [ 0, 0 ], [ 0, 0 ] ], "31" : [], "32" : [ [ 1, 0 ], [ -1, 0 ], [ 0, -1 ], [ 0, 1 ] ], "01" : [ [ 1, 0 ], [ -1, 0 ], [ 0, 1 ], [ 0, -1 ] ], "03" : [ [ 1, 0 ], [ -1, 0 ], [ 0, 0 ], [ 0, 0 ] ], "02" : []}, "l3_kicks" : {"10" : [ [ 1, 0 ], [ -1, 0 ] ], "12" : [ [ 0, -1 ], [ 0, 1 ] ], "13" : [], "20" : [], "21" : [ [ 0, 1 ], [ 0, -1 ] ], "23" : [ [ 1, 0 ], [ -1, 0 ] ], "30" : [ [ 0, 1 ], [ 0, -1 ] ], "31" : [], "32" : [ [ -1, 0 ], [ 1, 0 ] ], "01" : [ [ -1, 0 ], [ 1, 0 ] ], "03" : [ [ 0, -1 ], [ 0, 1 ] ], "02" : []}, "i5_kicks" : {"10" : [ [ 2, 0 ], [ -2, 0 ], [ 2, -1 ], [ -2, 2 ] ], "12" : [ [ -2, 0 ], [ 2, 0 ], [ -2, -2 ], [ 2, 1 ] ], "13" : [], "20" : [], "21" : [ [ 2, 0 ], [ -2, 0 ], [ 2, 2 ], [ -2, -1 ] ], "23" : [ [ 2, 0 ], [ -2, 0 ], [ 2, -1 ], [ -2, 2 ] ], "30" : [ [ 2, 0 ], [ -2, 0 ], [ 2, 2 ], [ -2, -1 ] ], "31" : [], "32" : [ [ -2, 0 ], [ 2, 0 ], [ -2, 1 ], [ 2, -2 ] ], "01" : [ [ -2, 0 ], [ 2, 0 ], [ -2, 1 ], [ 2, -2 ] ], "03" : [ [ -2, 0 ], [ 2, 0 ], [ -2, -2 ], [ 2, 1 ] ], "02" : []}, "oo_kicks" : {"10" : [ [ 1, 0 ], [ 0, -1 ], [ 1, 1 ], [ 1, -1 ], [ -1, 0 ], [ -1, -1 ], [ -1, 1 ] ], "12" : [ [ -1, 0 ], [ 0, -1 ], [ -1, 1 ], [ -1, -1 ], [ 1, 0 ], [ 1, -1 ], [ 1, 1 ] ], "13" : [[ 1, 0 ]], "20" : [[ 0, 1 ]], "21" : [ [ 0, -1 ], [ 1, -1 ], [ 0, 1 ], [ 1, 1 ], [ -1, 0 ], [ -1, -1 ], [ -1, 1 ] ], "23" : [ [ 0, -1 ], [ -1, -1 ], [ 0, 1 ], [ -1, 1 ], [ 1, 0 ], [ 1, -1 ], [ 1, 1 ] ], "30" : [ [ -1, 0 ], [ 0, -1 ], [ -1, 1 ], [ -1, -1 ], [ 1, 0 ], [ 1, -1 ], [ 1, 1 ] ], "31" : [[ -1, 0 ]], "32" : [ [ 1, 0 ], [ 0, -1 ], [ 1, 1 ], [ 1, -1 ], [ -1, 0 ], [ -1, -1 ], [ -1, 1 ] ], "01" : [ [ 0, -1 ], [ -1, -1 ], [ 0, 1 ], [ -1, 1 ], [ 1, 0 ], [ 1, -1 ], [ 1, 1 ] ], "03" : [ [ 0, -1 ], [ 1, -1 ], [ 0, 1 ], [ 1, 1 ], [ -1, 0 ], [ -1, -1 ], [ -1, 1 ] ], "02" : [[ 0, -1 ]]}, "additional_offsets" : {}, "spawn_rotation" : {}, "colorMap" : {"i1" : "i", "i2" : "i", "i3" : "i", "l3" : "j", "i5" : "i", "z" : "z", "l" : "l", "o" : "o", "s" : "s", "i" : "i", "j" : "j", "t" : "t", "oo" : "o", "g" : "g", "d" : "d", "gb" : "gb", "gbd" : "gbd"}, "preview_overrides" : {}},
			"SRS+" : {"kicks" : {"10" : [ [ 1, 0 ], [ 1, 1 ], [ 0, -2 ], [ 1, -2 ] ], "12" : [ [ 1, 0 ], [ 1, 1 ], [ 0, -2 ], [ 1, -2 ] ], "13" : [ [ 1, 0 ], [ 1, -2 ], [ 1, -1 ], [ 0, -2 ], [ 0, -1 ] ], "20" : [ [ 0, 1 ], [ -1, 1 ], [ 1, 1 ], [ -1, 0 ], [ 1, 0 ] ], "21" : [ [ -1, 0 ], [ -1, -1 ], [ 0, 2 ], [ -1, 2 ] ], "23" : [ [ 1, 0 ], [ 1, -1 ], [ 0, 2 ], [ 1, 2 ] ], "30" : [ [ -1, 0 ], [ -1, 1 ], [ 0, -2 ], [ -1, -2 ] ], "31" : [ [ -1, 0 ], [ -1, -2 ], [ -1, -1 ], [ 0, -2 ], [ 0, -1 ] ], "32" : [ [ -1, 0 ], [ -1, 1 ], [ 0, -2 ], [ -1, -2 ] ], "01" : [ [ -1, 0 ], [ -1, -1 ], [ 0, 2 ], [ -1, 2 ] ], "03" : [ [ 1, 0 ], [ 1, -1 ], [ 0, 2 ], [ 1, 2 ] ], "02" : [ [ 0, -1 ], [ 1, -1 ], [ -1, -1 ], [ 1, 0 ], [ -1, 0 ] ]}, "i_kicks" : {"10" : [ [ -1, 0 ], [ 2, 0 ], [ -1, 2 ], [ 2, -1 ] ], "12" : [ [ -1, 0 ], [ 2, 0 ], [ -1, -2 ], [ 2, 1 ] ], "13" : [[ 1, 0 ]], "20" : [[ 0, 1 ]], "21" : [ [ -2, 0 ], [ 1, 0 ], [ -2, -1 ], [ 1, 2 ] ], "23" : [ [ 2, 0 ], [ -1, 0 ], [ 2, -1 ], [ -1, 2 ] ], "30" : [ [ 1, 0 ], [ -2, 0 ], [ 1, 2 ], [ -2, -1 ] ], "31" : [[ -1, 0 ]], "32" : [ [ 1, 0 ], [ -2, 0 ], [ 1, -2 ], [ -2, 1 ] ], "01" : [ [ 1, 0 ], [ -2, 0 ], [ -2, 1 ], [ 1, -2 ] ], "03" : [ [ -1, 0 ], [ 2, 0 ], [ 2, 1 ], [ -1, -2 ] ], "02" : [[ 0, -1 ]]}, "i2_kicks" : {"10" : [ [ 0, 1 ], [ 1, 0 ], [ 1, 1 ] ], "12" : [ [ 1, 0 ], [ 0, -1 ], [ 1, 0 ] ], "13" : [], "20" : [], "21" : [ [ -1, 0 ], [ 0, 1 ], [ -1, 0 ] ], "23" : [ [ 0, 1 ], [ 1, 0 ], [ 1, -1 ] ], "30" : [ [ -1, 0 ], [ 0, 1 ], [ -1, 2 ] ], "31" : [], "32" : [ [ 0, -1 ], [ -1, 0 ], [ -1, 1 ] ], "01" : [ [ 0, -1 ], [ -1, 0 ], [ -1, -1 ] ], "03" : [ [ 1, 0 ], [ 0, -1 ], [ 1, -2 ] ], "02" : []}, "i3_kicks" : {"10" : [ [ -1, 0 ], [ 1, 0 ], [ 0, -1 ], [ 0, 1 ] ], "12" : [ [ 1, 0 ], [ -1, 0 ], [ 0, -2 ], [ 0, 2 ] ], "13" : [], "20" : [], "21" : [ [ -1, 0 ], [ 1, 0 ], [ 0, 2 ], [ 0, -2 ] ], "23" : [ [ -1, 0 ], [ 1, 0 ], [ 0, 1 ], [ 0, -1 ] ], "30" : [ [ -1, 0 ], [ 1, 0 ], [ 0, 0 ], [ 0, 0 ] ], "31" : [], "32" : [ [ 1, 0 ], [ -1, 0 ], [ 0, -1 ], [ 0, 1 ] ], "01" : [ [ 1, 0 ], [ -1, 0 ], [ 0, 1 ], [ 0, -1 ] ], "03" : [ [ 1, 0 ], [ -1, 0 ], [ 0, 0 ], [ 0, 0 ] ], "02" : []}, "l3_kicks" : {"10" : [ [ 1, 0 ], [ -1, 0 ] ], "12" : [ [ 0, -1 ], [ 0, 1 ] ], "13" : [], "20" : [], "21" : [ [ 0, 1 ], [ 0, -1 ] ], "23" : [ [ 1, 0 ], [ -1, 0 ] ], "30" : [ [ 0, 1 ], [ 0, -1 ] ], "31" : [], "32" : [ [ -1, 0 ], [ 1, 0 ] ], "01" : [ [ -1, 0 ], [ 1, 0 ] ], "03" : [ [ 0, -1 ], [ 0, 1 ] ], "02" : []}, "i5_kicks" : {"10" : [ [ 2, 0 ], [ -2, 0 ], [ 2, -1 ], [ -2, 2 ] ], "12" : [ [ -2, 0 ], [ 2, 0 ], [ -2, -2 ], [ 2, 1 ] ], "13" : [], "20" : [], "21" : [ [ 2, 0 ], [ -2, 0 ], [ 2, 2 ], [ -2, -1 ] ], "23" : [ [ 2, 0 ], [ -2, 0 ], [ 2, -1 ], [ -2, 2 ] ], "30" : [ [ 2, 0 ], [ -2, 0 ], [ 2, 2 ], [ -2, -1 ] ], "31" : [], "32" : [ [ -2, 0 ], [ 2, 0 ], [ -2, 1 ], [ 2, -2 ] ], "01" : [ [ -2, 0 ], [ 2, 0 ], [ -2, 1 ], [ 2, -2 ] ], "03" : [ [ -2, 0 ], [ 2, 0 ], [ -2, -2 ], [ 2, 1 ] ], "02" : []}, "oo_kicks" : {"10" : [ [ 1, 0 ], [ 0, -1 ], [ 1, 1 ], [ 1, -1 ], [ -1, 0 ], [ -1, -1 ], [ -1, 1 ] ], "12" : [ [ -1, 0 ], [ 0, -1 ], [ -1, 1 ], [ -1, -1 ], [ 1, 0 ], [ 1, -1 ], [ 1, 1 ] ], "13" : [[ 1, 0 ]], "20" : [[ 0, 1 ]], "21" : [ [ 0, -1 ], [ 1, -1 ], [ 0, 1 ], [ 1, 1 ], [ -1, 0 ], [ -1, -1 ], [ -1, 1 ] ], "23" : [ [ 0, -1 ], [ -1, -1 ], [ 0, 1 ], [ -1, 1 ], [ 1, 0 ], [ 1, -1 ], [ 1, 1 ] ], "30" : [ [ -1, 0 ], [ 0, -1 ], [ -1, 1 ], [ -1, -1 ], [ 1, 0 ], [ 1, -1 ], [ 1, 1 ] ], "31" : [[ -1, 0 ]], "32" : [ [ 1, 0 ], [ 0, -1 ], [ 1, 1 ], [ 1, -1 ], [ -1, 0 ], [ -1, -1 ], [ -1, 1 ] ], "01" : [ [ 0, -1 ], [ -1, -1 ], [ 0, 1 ], [ -1, 1 ], [ 1, 0 ], [ 1, -1 ], [ 1, 1 ] ], "03" : [ [ 0, -1 ], [ 1, -1 ], [ 0, 1 ], [ 1, 1 ], [ -1, 0 ], [ -1, -1 ], [ -1, 1 ] ], "02" : [[ 0, -1 ]]}, "additional_offsets" : {}, "spawn_rotation" : {}, "colorMap" : {"i1" : "i", "i2" : "i", "i3" : "i", "l3" : "j", "i5" : "i", "z" : "z", "l" : "l", "o" : "o", "s" : "s", "i" : "i", "j" : "j", "t" : "t", "oo" : "o", "g" : "g", "d" : "d", "gb" : "gb", "gbd" : "gbd"}, "preview_overrides" : {}},
			"SRS-X" : {"kicks" : {"10" : [ [ 1, 0 ], [ 1, 1 ], [ 0, -2 ], [ 1, -2 ] ], "12" : [ [ 1, 0 ], [ 1, 1 ], [ 0, -2 ], [ 1, -2 ] ], "13" : [ [ 0, 1 ], [ 0, 2 ], [ -1, 1 ], [ -1, 2 ], [ 0, -1 ], [ 0, -2 ], [ -1, -1 ], [ -1, -2 ], [ 1, 0 ], [ 0, 3 ], [ 0, -3 ] ], "20" : [ [ -1, 0 ], [ -2, 0 ], [ -1, -1 ], [ -2, -1 ], [ 1, 0 ], [ 2, 0 ], [ 1, -1 ], [ 2, -1 ], [ 0, 1 ], [ -3, 0 ], [ 3, 0 ] ], "21" : [ [ -1, 0 ], [ -1, -1 ], [ 0, 2 ], [ -1, 2 ] ], "23" : [ [ 1, 0 ], [ 1, -1 ], [ 0, 2 ], [ 1, 2 ] ], "30" : [ [ -1, 0 ], [ -1, 1 ], [ 0, -2 ], [ -1, -2 ] ], "31" : [ [ 0, 1 ], [ 0, 2 ], [ 1, 1 ], [ 1, 2 ], [ 0, -1 ], [ 0, -2 ], [ 1, -1 ], [ 1, -2 ], [ -1, 0 ], [ 0, 3 ], [ 0, -3 ] ], "32" : [ [ -1, 0 ], [ -1, 1 ], [ 0, -2 ], [ -1, -2 ] ], "01" : [ [ -1, 0 ], [ -1, -1 ], [ 0, 2 ], [ -1, 2 ] ], "03" : [ [ 1, 0 ], [ 1, -1 ], [ 0, 2 ], [ 1, 2 ] ], "02" : [ [ 1, 0 ], [ 2, 0 ], [ 1, 1 ], [ 2, 1 ], [ -1, 0 ], [ -2, 0 ], [ -1, 1 ], [ -2, 1 ], [ 0, -1 ], [ 3, 0 ], [ -3, 0 ] ]}, "i_kicks" : {"10" : [ [ 2, 0 ], [ -1, 0 ], [ 2, -1 ], [ -1, 2 ] ], "12" : [ [ -1, 0 ], [ 2, 0 ], [ -1, -2 ], [ 2, 1 ] ], "13" : [ [ 0, 1 ], [ 0, 2 ], [ 0, -1 ], [ 0, -2 ], [ -1, 0 ] ], "20" : [ [ 1, 0 ], [ 2, 0 ], [ -1, 0 ], [ -2, 0 ], [ 0, -1 ] ], "21" : [ [ 1, 0 ], [ -2, 0 ], [ 1, 2 ], [ -2, -1 ] ], "23" : [ [ 2, 0 ], [ -1, 0 ], [ 2, -1 ], [ -1, 2 ] ], "30" : [ [ 1, 0 ], [ -2, 0 ], [ 1, 2 ], [ -2, -1 ] ], "31" : [ [ 0, 1 ], [ 0, 2 ], [ 0, -1 ], [ 0, -2 ], [ 1, 0 ] ], "32" : [ [ -2, 0 ], [ 1, 0 ], [ -2, 1 ], [ 1, -2 ] ], "01" : [ [ -2, 0 ], [ 1, 0 ], [ -2, 1 ], [ 1, -2 ] ], "03" : [ [ -1, 0 ], [ 2, 0 ], [ -1, -2 ], [ 2, 1 ] ], "02" : [ [ -1, 0 ], [ -2, 0 ], [ 1, 0 ], [ 2, 0 ], [ 0, 1 ] ]}, "i2_kicks" : {"10" : [ [ 0, 1 ], [ 1, 0 ], [ 1, 1 ] ], "12" : [ [ 1, 0 ], [ 0, -1 ], [ 1, 0 ] ], "13" : [ [ 0, 1 ], [ 0, 2 ], [ 0, -1 ], [ 0, -2 ], [ -1, 0 ] ], "20" : [ [ 1, 0 ], [ 2, 0 ], [ -1, 0 ], [ -2, 0 ], [ 0, -1 ] ], "21" : [ [ -1, 0 ], [ 0, 1 ], [ -1, 0 ] ], "23" : [ [ 0, 1 ], [ 1, 0 ], [ 1, -1 ] ], "30" : [ [ -1, 0 ], [ 0, 1 ], [ -1, 2 ] ], "31" : [ [ 0, 1 ], [ 0, 2 ], [ 0, -1 ], [ 0, -2 ], [ 1, 0 ] ], "32" : [ [ 0, -1 ], [ -1, 0 ], [ -1, 1 ] ], "01" : [ [ 0, -1 ], [ -1, 0 ], [ -1, -1 ] ], "03" : [ [ 1, 0 ], [ 0, -1 ], [ 1, -2 ] ], "02" : [ [ -1, 0 ], [ -2, 0 ], [ 1, 0 ], [ 2, 0 ], [ 0, 1 ] ]}, "i3_kicks" : {"10" : [ [ -1, 0 ], [ 1, 0 ], [ 0, -1 ], [ 0, 1 ] ], "12" : [ [ 1, 0 ], [ -1, 0 ], [ 0, -2 ], [ 0, 2 ] ], "13" : [ [ 0, 1 ], [ 0, 2 ], [ -1, 1 ], [ -1, 2 ], [ 0, -1 ], [ 0, -2 ], [ -1, -1 ], [ -1, -2 ], [ 1, 0 ], [ 0, 3 ], [ 0, -3 ] ], "20" : [ [ -1, 0 ], [ -2, 0 ], [ -1, -1 ], [ -2, -1 ], [ 1, 0 ], [ 2, 0 ], [ 1, -1 ], [ 2, -1 ], [ 0, 1 ], [ -3, 0 ], [ 3, 0 ] ], "21" : [ [ -1, 0 ], [ 1, 0 ], [ 0, 2 ], [ 0, -2 ] ], "23" : [ [ -1, 0 ], [ 1, 0 ], [ 0, 1 ], [ 0, -1 ] ], "30" : [ [ -1, 0 ], [ 1, 0 ], [ 0, 0 ], [ 0, 0 ] ], "31" : [ [ 0, 1 ], [ 0, 2 ], [ 1, 1 ], [ 1, 2 ], [ 0, -1 ], [ 0, -2 ], [ 1, -1 ], [ 1, -2 ], [ -1, 0 ], [ 0, 3 ], [ 0, -3 ] ], "32" : [ [ 1, 0 ], [ -1, 0 ], [ 0, -1 ], [ 0, 1 ] ], "01" : [ [ 1, 0 ], [ -1, 0 ], [ 0, 1 ], [ 0, -1 ] ], "03" : [ [ 1, 0 ], [ -1, 0 ], [ 0, 0 ], [ 0, 0 ] ], "02" : [ [ 1, 0 ], [ 2, 0 ], [ 1, 1 ], [ 2, 1 ], [ -1, 0 ], [ -2, 0 ], [ -1, 1 ], [ -2, 1 ], [ 0, -1 ], [ 3, 0 ], [ -3, 0 ] ]}, "l3_kicks" : {"10" : [ [ 1, 0 ], [ -1, 0 ] ], "12" : [ [ 0, -1 ], [ 0, 1 ] ], "13" : [ [ 0, 1 ], [ 0, 2 ], [ -1, 1 ], [ -1, 2 ], [ 0, -1 ], [ 0, -2 ], [ -1, -1 ], [ -1, -2 ], [ 1, 0 ], [ 0, 3 ], [ 0, -3 ] ], "20" : [ [ -1, 0 ], [ -2, 0 ], [ -1, -1 ], [ -2, -1 ], [ 1, 0 ], [ 2, 0 ], [ 1, -1 ], [ 2, -1 ], [ 0, 1 ], [ -3, 0 ], [ 3, 0 ] ], "21" : [ [ 0, 1 ], [ 0, -1 ] ], "23" : [ [ 1, 0 ], [ -1, 0 ] ], "30" : [ [ 0, 1 ], [ 0, -1 ] ], "31" : [ [ 0, 1 ], [ 0, 2 ], [ 1, 1 ], [ 1, 2 ], [ 0, -1 ], [ 0, -2 ], [ 1, -1 ], [ 1, -2 ], [ -1, 0 ], [ 0, 3 ], [ 0, -3 ] ], "32" : [ [ -1, 0 ], [ 1, 0 ] ], "01" : [ [ -1, 0 ], [ 1, 0 ] ], "03" : [ [ 0, -1 ], [ 0, 1 ] ], "02" : [ [ 1, 0 ], [ 2, 0 ], [ 1, 1 ], [ 2, 1 ], [ -1, 0 ], [ -2, 0 ], [ -1, 1 ], [ -2, 1 ], [ 0, -1 ], [ 3, 0 ], [ -3, 0 ] ]}, "i5_kicks" : {"10" : [ [ 2, 0 ], [ -2, 0 ], [ 2, -1 ], [ -2, 2 ] ], "12" : [ [ -2, 0 ], [ 2, 0 ], [ -2, -2 ], [ 2, 1 ] ], "13" : [ [ 0, 1 ], [ 0, 2 ], [ -1, 1 ], [ -1, 2 ], [ 0, -1 ], [ 0, -2 ], [ -1, -1 ], [ -1, -2 ], [ 1, 0 ], [ 0, 3 ], [ 0, -3 ] ], "20" : [ [ -1, 0 ], [ -2, 0 ], [ -1, -1 ], [ -2, -1 ], [ 1, 0 ], [ 2, 0 ], [ 1, -1 ], [ 2, -1 ], [ 0, 1 ], [ -3, 0 ], [ 3, 0 ] ], "21" : [ [ 2, 0 ], [ -2, 0 ], [ 2, 2 ], [ -2, -1 ] ], "23" : [ [ 2, 0 ], [ -2, 0 ], [ 2, -1 ], [ -2, 2 ] ], "30" : [ [ 2, 0 ], [ -2, 0 ], [ 2, 2 ], [ -2, -1 ] ], "31" : [ [ 0, 1 ], [ 0, 2 ], [ 1, 1 ], [ 1, 2 ], [ 0, -1 ], [ 0, -2 ], [ 1, -1 ], [ 1, -2 ], [ -1, 0 ], [ 0, 3 ], [ 0, -3 ] ], "32" : [ [ -2, 0 ], [ 2, 0 ], [ -2, 1 ], [ 2, -2 ] ], "01" : [ [ -2, 0 ], [ 2, 0 ], [ -2, 1 ], [ 2, -2 ] ], "03" : [ [ -2, 0 ], [ 2, 0 ], [ -2, -2 ], [ 2, 1 ] ], "02" : [ [ 1, 0 ], [ 2, 0 ], [ 1, 1 ], [ 2, 1 ], [ -1, 0 ], [ -2, 0 ], [ -1, 1 ], [ -2, 1 ], [ 0, -1 ], [ 3, 0 ], [ -3, 0 ] ]}, "oo_kicks" : {"10" : [ [ 1, 0 ], [ 0, -1 ], [ 1, 1 ], [ 1, -1 ], [ -1, 0 ], [ -1, -1 ], [ -1, 1 ] ], "12" : [ [ -1, 0 ], [ 0, -1 ], [ -1, 1 ], [ -1, -1 ], [ 1, 0 ], [ 1, -1 ], [ 1, 1 ] ], "13" : [[ 1, 0 ]], "20" : [[ 0, 1 ]], "21" : [ [ 0, -1 ], [ 1, -1 ], [ 0, 1 ], [ 1, 1 ], [ -1, 0 ], [ -1, -1 ], [ -1, 1 ] ], "23" : [ [ 0, -1 ], [ -1, -1 ], [ 0, 1 ], [ -1, 1 ], [ 1, 0 ], [ 1, -1 ], [ 1, 1 ] ], "30" : [ [ -1, 0 ], [ 0, -1 ], [ -1, 1 ], [ -1, -1 ], [ 1, 0 ], [ 1, -1 ], [ 1, 1 ] ], "31" : [[ -1, 0 ]], "32" : [ [ 1, 0 ], [ 0, -1 ], [ 1, 1 ], [ 1, -1 ], [ -1, 0 ], [ -1, -1 ], [ -1, 1 ] ], "01" : [ [ 0, -1 ], [ -1, -1 ], [ 0, 1 ], [ -1, 1 ], [ 1, 0 ], [ 1, -1 ], [ 1, 1 ] ], "03" : [ [ 0, -1 ], [ 1, -1 ], [ 0, 1 ], [ 1, 1 ], [ -1, 0 ], [ -1, -1 ], [ -1, 1 ] ], "02" : [[ 0, -1 ]]}, "additional_offsets" : {}, "spawn_rotation" : {}, "colorMap" : {"i1" : "i", "i2" : "i", "i3" : "i", "l3" : "j", "i5" : "i", "z" : "z", "l" : "l", "o" : "o", "s" : "s", "i" : "i", "j" : "j", "t" : "t", "oo" : "o", "g" : "g", "d" : "d", "gb" : "gb", "gbd" : "gbd"}, "preview_overrides" : {}},
			"TETRA-X" : {"kicks" : {"10" : [ [ 0, 1 ], [ 1, 0 ], [ -1, 0 ], [ 1, 1 ], [ -1, 1 ], [ 0, -1 ], [ 1, -1 ], [ -1, -1 ] ], "12" : [ [ 0, 1 ], [ -1, 0 ], [ 1, 0 ], [ -1, 1 ], [ 1, 1 ], [ 0, -1 ], [ -1, -1 ], [ 1, -1 ] ], "13" : [ [ 0, 1 ], [ 0, -1 ], [ -1, 0 ], [ 1, 0 ] ], "20" : [ [ 0, 1 ], [ 0, -1 ], [ -1, 0 ], [ 1, 0 ] ], "21" : [ [ 0, 1 ], [ 1, 0 ], [ -1, 0 ], [ 1, 1 ], [ -1, 1 ], [ 0, -1 ], [ 1, -1 ], [ -1, -1 ] ], "23" : [ [ 0, 1 ], [ -1, 0 ], [ 1, 0 ], [ -1, 1 ], [ 1, 1 ], [ 0, -1 ], [ -1, -1 ], [ 1, -1 ] ], "30" : [ [ 0, 1 ], [ -1, 0 ], [ 1, 0 ], [ -1, 1 ], [ 1, 1 ], [ 0, -1 ], [ -1, -1 ], [ 1, -1 ] ], "31" : [ [ 0, 1 ], [ 0, -1 ], [ -1, 0 ], [ 1, 0 ] ], "32" : [ [ 0, 1 ], [ 1, 0 ], [ -1, 0 ], [ 1, 1 ], [ -1, 1 ], [ 0, -1 ], [ 1, -1 ], [ -1, -1 ] ], "01" : [ [ 0, 1 ], [ -1, 0 ], [ 1, 0 ], [ -1, 1 ], [ 1, 1 ], [ 0, -1 ], [ -1, -1 ], [ 1, -1 ] ], "03" : [ [ 0, 1 ], [ 1, 0 ], [ -1, 0 ], [ 1, 1 ], [ -1, 1 ], [ 0, -1 ], [ 1, -1 ], [ -1, -1 ] ], "02" : [ [ 0, 1 ], [ 0, -1 ], [ -1, 0 ], [ 1, 0 ] ]}, "i_kicks" : {"10" : [ [ 0, -1 ], [ 0, -2 ], [ 0, 1 ], [ -1, 0 ], [ 1, 0 ], [ 2, 0 ] ], "12" : [ [ 0, -1 ], [ 0, -2 ], [ 0, 1 ], [ -1, 0 ], [ 1, 0 ], [ 2, 0 ] ], "13" : [ [ 0, -1 ], [ 0, 1 ] ], "20" : [ [ 0, -1 ], [ 0, 1 ] ], "21" : [ [ 0, 1 ], [ 0, 2 ], [ 0, -1 ], [ -1, 1 ], [ 1, 1 ], [ -1, 2 ], [ 1, 2 ] ], "23" : [ [ 0, 1 ], [ 0, 2 ], [ 0, -1 ], [ 1, 1 ], [ -1, 1 ], [ 1, 2 ], [ -1, 2 ] ], "30" : [ [ 0, -1 ], [ 0, -2 ], [ 0, 1 ], [ 1, 0 ], [ -1, 0 ], [ -2, 0 ] ], "31" : [ [ 0, -1 ], [ 0, 1 ] ], "32" : [ [ 0, -1 ], [ 0, -2 ], [ 0, 1 ], [ 1, 0 ], [ -1, 0 ], [ -2, 0 ] ], "01" : [ [ 0, -1 ], [ 0, -2 ], [ 0, 1 ], [ 1, -1 ], [ -1, -1 ], [ 1, -2 ], [ -1, -2 ] ], "03" : [ [ 0, -1 ], [ 0, -2 ], [ 0, 1 ], [ -1, -1 ], [ 1, -1 ], [ -1, -2 ], [ 1, -2 ] ], "02" : [ [ 0, -1 ], [ 0, 1 ] ]}, "additional_offsets" : {}, "spawn_rotation" : {}, "colorMap" : {"i1" : "i", "i2" : "i", "i3" : "i", "l3" : "j", "i5" : "i", "z" : "z", "l" : "o", "o" : "s", "s" : "i", "i" : "l", "j" : "j", "t" : "t", "oo" : "o", "g" : "g", "d" : "d", "gb" : "gb", "gbd" : "gbd"}, "preview_overrides" : {}},
			"NRS" : {"kicks" : {"10" : [], "12" : [], "13" : [], "20" : [], "21" : [], "23" : [], "30" : [], "31" : [], "32" : [], "01" : [], "03" : [], "02" : []}, "additional_offsets" : {"z" : [ [ 1, 1 ], [ 1, 0 ], [ 1, 0 ], [ 2, 0 ] ], "l" : [ [ 1, 0 ], [ 1, 0 ], [ 1, 0 ], [ 1, 0 ] ], "o" : [ [ 0, 0 ], [ 0, 0 ], [ 0, 0 ], [ 0, 0 ] ], "s" : [ [ 1, 1 ], [ 1, 0 ], [ 1, 0 ], [ 2, 0 ] ], "i" : [ [ 0, 1 ], [ 0, 0 ], [ 0, 0 ], [ 1, 0 ] ], "j" : [ [ 1, 0 ], [ 1, 0 ], [ 1, 0 ], [ 1, 0 ] ], "t" : [ [ 1, 0 ], [ 1, 0 ], [ 1, 0 ], [ 1, 0 ] ]}, "spawn_rotation" : {"z" : 0, "l" : 2, "o" : 0, "s" : 0, "i" : 0, "j" : 2, "t" : 2}, "colorMap" : {"i1" : "i", "i2" : "i", "i3" : "i", "l3" : "j", "i5" : "i", "z" : "z", "l" : "l", "o" : "o", "s" : "s", "i" : "i", "j" : "j", "t" : "t", "oo" : "o", "g" : "g", "d" : "d", "gb" : "gb", "gbd" : "gbd"}, "preview_overrides" : {"l" : [ [ 0, 0, 201 ], [ 1, 0, 68 ], [ 2, 0, 124 ], [ 0, 1, 31 ] ], "j" : [ [ 0, 0, 199 ], [ 1, 0, 68 ], [ 2, 0, 114 ], [ 2, 1, 31 ] ], "t" : [ [ 0, 0, 199 ], [ 1, 0, 74 ], [ 2, 0, 124 ], [ 1, 1, 31 ] ]}},
			"ARS" : {"kicks" : {"10" : [ [ 1, 0 ], [ -1, 0 ] ], "12" : [ [ 1, 0 ], [ -1, 0 ] ], "13" : [ [ 1, 0 ], [ -1, 0 ] ], "20" : [ [ 1, 0 ], [ -1, 0 ] ], "21" : [ [ 1, 0 ], [ -1, 0 ] ], "23" : [ [ 1, 0 ], [ -1, 0 ] ], "30" : [ [ 1, 0 ], [ -1, 0 ] ], "31" : [ [ 1, 0 ], [ -1, 0 ] ], "32" : [ [ 1, 0 ], [ -1, 0 ] ], "01" : [ [ 1, 0 ], [ -1, 0 ] ], "03" : [ [ 1, 0 ], [ -1, 0 ] ], "02" : [ [ 1, 0 ], [ -1, 0 ] ]}, "additional_offsets" : {"i1" : [ [ 0, 0 ], [ 0, 0 ], [ 0, 0 ], [ 0, 0 ] ], "z" : [ [ 0, 1 ], [ 0, 0 ], [ 0, 0 ], [ 1, 0 ] ], "l" : [ [ 0, 1 ], [ 0, 0 ], [ 0, 0 ], [ 0, 0 ] ], "o" : [ [ 0, 0 ], [ 0, 0 ], [ 0, 0 ], [ 0, 0 ] ], "s" : [ [ 0, 1 ], [ -1, 0 ], [ 0, 0 ], [ 0, 0 ] ], "i" : [ [ 0, 0 ], [ 0, 0 ], [ 0, -1 ], [ 1, 0 ] ], "j" : [ [ 0, 1 ], [ 0, 0 ], [ 0, 0 ], [ 0, 0 ] ], "t" : [ [ 0, 1 ], [ 0, 0 ], [ 0, 0 ], [ 0, 0 ] ]}, "spawn_rotation" : {"z" : 0, "l" : 2, "o" : 0, "s" : 0, "i" : 0, "j" : 2, "t" : 2}, "colorMap" : {"i1" : "i", "i2" : "i", "i3" : "i", "l3" : "j", "i5" : "i", "z" : "s", "l" : "l", "o" : "o", "s" : "t", "i" : "z", "j" : "j", "t" : "i", "g" : "g", "d" : "d", "gb" : "gb", "gbd" : "gbd"}, "preview_overrides" : {"l" : [ [ 0, 0, 201 ], [ 1, 0, 68 ], [ 2, 0, 124 ], [ 0, 1, 31 ] ], "j" : [ [ 0, 0, 199 ], [ 1, 0, 68 ], [ 2, 0, 114 ], [ 2, 1, 31 ] ], "t" : [ [ 0, 0, 199 ], [ 1, 0, 74 ], [ 2, 0, 124 ], [ 1, 1, 31 ] ]}, "center_column" : [ [ -1, -1 ], [ 0, -1 ], [ 1, -1 ], [ -1, 0 ], [ 0, 0 ], [ 1, 0 ], [ -1, 1 ], [ 0, 1 ], [ 1, 1 ] ]},
			"ASC" : {"kicks" : {"10" : [ [ 1, 0 ], [ 0, 1 ], [ 1, 1 ], [ 0, 2 ], [ 1, 2 ], [ 2, 0 ], [ 2, 1 ], [ 2, 2 ], [ -1, 0 ], [ -1, 1 ], [ 0, -1 ], [ 1, -1 ], [ 2, -1 ], [ -1, 2 ], [ -2, 0 ], [ 0, -2 ], [ 1, -2 ], [ 2, -2 ], [ -2, 1 ], [ -2, 2 ], [ -1, -1 ] ], "12" : [ [ -1, 0 ], [ 0, 1 ], [ -1, 1 ], [ 0, 2 ], [ -1, 2 ], [ -2, 0 ], [ -2, 1 ], [ -2, 2 ], [ 1, 0 ], [ 1, 1 ], [ 0, -1 ], [ -1, -1 ], [ -2, -1 ], [ 1, 2 ], [ 2, 0 ], [ 0, -2 ], [ -1, -2 ], [ -2, -2 ], [ 2, 1 ], [ 2, 2 ], [ 1, -1 ] ], "13" : [], "20" : [], "21" : [ [ 1, 0 ], [ 0, 1 ], [ 1, 1 ], [ 0, 2 ], [ 1, 2 ], [ 2, 0 ], [ 2, 1 ], [ 2, 2 ], [ -1, 0 ], [ -1, 1 ], [ 0, -1 ], [ 1, -1 ], [ 2, -1 ], [ -1, 2 ], [ -2, 0 ], [ 0, -2 ], [ 1, -2 ], [ 2, -2 ], [ -2, 1 ], [ -2, 2 ], [ -1, -1 ] ], "23" : [ [ -1, 0 ], [ 0, 1 ], [ -1, 1 ], [ 0, 2 ], [ -1, 2 ], [ -2, 0 ], [ -2, 1 ], [ -2, 2 ], [ 1, 0 ], [ 1, 1 ], [ 0, -1 ], [ -1, -1 ], [ -2, -1 ], [ 1, 2 ], [ 2, 0 ], [ 0, -2 ], [ -1, -2 ], [ -2, -2 ], [ 2, 1 ], [ 2, 2 ], [ 1, -1 ] ], "30" : [ [ -1, 0 ], [ 0, 1 ], [ -1, 1 ], [ 0, 2 ], [ -1, 2 ], [ -2, 0 ], [ -2, 1 ], [ -2, 2 ], [ 1, 0 ], [ 1, 1 ], [ 0, -1 ], [ -1, -1 ], [ -2, -1 ], [ 1, 2 ], [ 2, 0 ], [ 0, -2 ], [ -1, -2 ], [ -2, -2 ], [ 2, 1 ], [ 2, 2 ], [ 1, -1 ] ], "31" : [], "32" : [ [ 1, 0 ], [ 0, 1 ], [ 1, 1 ], [ 0, 2 ], [ 1, 2 ], [ 2, 0 ], [ 2, 1 ], [ 2, 2 ], [ -1, 0 ], [ -1, 1 ], [ 0, -1 ], [ 1, -1 ], [ 2, -1 ], [ -1, 2 ], [ -2, 0 ], [ 0, -2 ], [ 1, -2 ], [ 2, -2 ], [ -2, 1 ], [ -2, 2 ], [ -1, -1 ] ], "01" : [ [ -1, 0 ], [ 0, 1 ], [ -1, 1 ], [ 0, 2 ], [ -1, 2 ], [ -2, 0 ], [ -2, 1 ], [ -2, 2 ], [ 1, 0 ], [ 1, 1 ], [ 0, -1 ], [ -1, -1 ], [ -2, -1 ], [ 1, 2 ], [ 2, 0 ], [ 0, -2 ], [ -1, -2 ], [ -2, -2 ], [ 2, 1 ], [ 2, 2 ], [ 1, -1 ] ], "03" : [ [ 1, 0 ], [ 0, 1 ], [ 1, 1 ], [ 0, 2 ], [ 1, 2 ], [ 2, 0 ], [ 2, 1 ], [ 2, 2 ], [ -1, 0 ], [ -1, 1 ], [ 0, -1 ], [ 1, -1 ], [ 2, -1 ], [ -1, 2 ], [ -2, 0 ], [ 0, -2 ], [ 1, -2 ], [ 2, -2 ], [ -2, 1 ], [ -2, 2 ], [ -1, -1 ] ], "02" : []}, "i_kicks" : {"10" : [ [ 1, 0 ], [ 0, 1 ], [ 1, 1 ], [ 0, 2 ], [ 1, 2 ], [ 2, 0 ], [ 2, 1 ], [ 2, 2 ], [ -1, 0 ], [ -1, 1 ], [ 0, -1 ], [ 1, -1 ], [ 2, -1 ], [ -1, 2 ], [ -2, 0 ], [ 0, -2 ], [ 1, -2 ], [ 2, -2 ], [ -2, 1 ], [ -2, 2 ], [ -1, -1 ] ], "12" : [ [ -1, 0 ], [ 0, 1 ], [ -1, 1 ], [ 0, 2 ], [ -1, 2 ], [ -2, 0 ], [ -2, 1 ], [ -2, 2 ], [ 1, 0 ], [ 1, 1 ], [ 0, -1 ], [ -1, -1 ], [ -2, -1 ], [ 1, 2 ], [ 2, 0 ], [ 0, -2 ], [ -1, -2 ], [ -2, -2 ], [ 2, 1 ], [ 2, 2 ], [ 1, -1 ] ], "13" : [], "20" : [], "21" : [ [ 1, 0 ], [ 0, 1 ], [ 1, 1 ], [ 0, 2 ], [ 1, 2 ], [ 2, 0 ], [ 2, 1 ], [ 2, 2 ], [ -1, 0 ], [ -1, 1 ], [ 0, -1 ], [ 1, -1 ], [ 2, -1 ], [ -1, 2 ], [ -2, 0 ], [ 0, -2 ], [ 1, -2 ], [ 2, -2 ], [ -2, 1 ], [ -2, 2 ], [ -1, -1 ] ], "23" : [ [ -1, 0 ], [ 0, 1 ], [ -1, 1 ], [ 0, 2 ], [ -1, 2 ], [ -2, 0 ], [ -2, 1 ], [ -2, 2 ], [ 1, 0 ], [ 1, 1 ], [ 0, -1 ], [ -1, -1 ], [ -2, -1 ], [ 1, 2 ], [ 2, 0 ], [ 0, -2 ], [ -1, -2 ], [ -2, -2 ], [ 2, 1 ], [ 2, 2 ], [ 1, -1 ] ], "30" : [ [ -1, 0 ], [ 0, 1 ], [ -1, 1 ], [ 0, 2 ], [ -1, 2 ], [ -2, 0 ], [ -2, 1 ], [ -2, 2 ], [ 1, 0 ], [ 1, 1 ], [ 0, -1 ], [ -1, -1 ], [ -2, -1 ], [ 1, 2 ], [ 2, 0 ], [ 0, -2 ], [ -1, -2 ], [ -2, -2 ], [ 2, 1 ], [ 2, 2 ], [ 1, -1 ] ], "31" : [], "32" : [ [ 1, 0 ], [ 0, 1 ], [ 1, 1 ], [ 0, 2 ], [ 1, 2 ], [ 2, 0 ], [ 2, 1 ], [ 2, 2 ], [ -1, 0 ], [ -1, 1 ], [ 0, -1 ], [ 1, -1 ], [ 2, -1 ], [ -1, 2 ], [ -2, 0 ], [ 0, -2 ], [ 1, -2 ], [ 2, -2 ], [ -2, 1 ], [ -2, 2 ], [ -1, -1 ] ], "01" : [ [ -1, 0 ], [ 0, 1 ], [ -1, 1 ], [ 0, 2 ], [ -1, 2 ], [ -2, 0 ], [ -2, 1 ], [ -2, 2 ], [ 1, 0 ], [ 1, 1 ], [ 0, -1 ], [ -1, -1 ], [ -2, -1 ], [ 1, 2 ], [ 2, 0 ], [ 0, -2 ], [ -1, -2 ], [ -2, -2 ], [ 2, 1 ], [ 2, 2 ], [ 1, -1 ] ], "03" : [ [ 1, 0 ], [ 0, 1 ], [ 1, 1 ], [ 0, 2 ], [ 1, 2 ], [ 2, 0 ], [ 2, 1 ], [ 2, 2 ], [ -1, 0 ], [ -1, 1 ], [ 0, -1 ], [ 1, -1 ], [ 2, -1 ], [ -1, 2 ], [ -2, 0 ], [ 0, -2 ], [ 1, -2 ], [ 2, -2 ], [ -2, 1 ], [ -2, 2 ], [ -1, -1 ] ], "02" : []}, "allow_o_kick" : true, "additional_offsets" : {"i1" : [ [ 0, 0 ], [ 0, 0 ], [ 0, 0 ], [ 0, 0 ] ], "z" : [ [ 0, 0 ], [ 0, 0 ], [ 0, 0 ], [ 0, 0 ] ], "l" : [ [ 0, 0 ], [ 0, 0 ], [ 0, 0 ], [ 0, 0 ] ], "o" : [ [ 0, 0 ], [ 0, 1 ], [ -1, 1 ], [ -1, 0 ] ], "s" : [ [ 0, 0 ], [ 0, 0 ], [ 0, 0 ], [ 0, 0 ] ], "i" : [ [ 0, 0 ], [ 0, -1 ], [ 1, -1 ], [ 1, 0 ] ], "j" : [ [ 0, 0 ], [ 0, 0 ], [ 0, 0 ], [ 0, 0 ] ], "t" : [ [ 0, 0 ], [ 0, 0 ], [ 0, 0 ], [ 0, 0 ] ]}, "colorMap" : {"i1" : "i", "i2" : "i", "i3" : "i", "l3" : "j", "i5" : "i", "z" : "z", "l" : "l", "o" : "o", "s" : "s", "i" : "i", "j" : "j", "t" : "t", "oo" : "o", "g" : "g", "d" : "d", "gb" : "gb", "gbd" : "gbd"}, "spawn_rotation" : {}, "preview_overrides" : {}},
			"none" :
					{
						"kicks" : {"10" : [], "12" : [], "13" : [], "20" : [], "21" : [], "23" : [], "30" : [], "31" : [], "32" : [], "01" : [], "03" : [], "02" : []},
						"additional_offsets" : {},
						"colorMap" : {"i1" : "i", "i2" : "i", "i3" : "i", "l3" : "j", "i5" : "i", "z" : "z", "l" : "l", "o" : "o", "s" : "s", "i" : "i", "j" : "j", "t" : "t", "oo" : "o", "g" : "g", "d" : "d", "gb" : "gb", "gbd" : "gbd"},
						"spawn_rotation" : {},
						"preview_overrides" : {}
					}
		}
	)");