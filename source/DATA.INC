; ---------------------------------------------------------------------------
; - Stars - Constants (consts.inc)                                          -
; - Copyright (C) 1998-2024 Alexandru Groza of Microprogramming TECHNIQUES  -
; - All rights reserved.                                                    -
; ---------------------------------------------------------------------------
; - License: GNU General Public License v3.0                                -
; ---------------------------------------------------------------------------

; star animation frames (array of glyph and color pairs)
; ---------------------------------------------------------------------------
  kStars         DB  ' ',00h,'ù',03h,'',0Bh,'+',0Fh,'',0Eh,'',05h,'ú',06h

; global variables section
; ---------------------------------------------------------------------------
  dStarCount     DB  0
  dInflatedCount DB  0
