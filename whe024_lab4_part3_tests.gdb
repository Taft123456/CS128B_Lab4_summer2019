# Test sequence from Wait_Command: A2, A1 => PORTB: 0x01
test "PINA: 0x04, 0x02 => PORTB: 0x01, state: Door_Unlock"
set state = Wait_Command
setPINA 0x04
continue 2
setPINA 0x02
continue 2
expectPORTB 0x01
checkResult

# Test sequence from Wait_Command: A7 => PORTB: 0x00
test "PINA: 0x80 => PORTB: 0x00, state: Door_Relock"
set state = Wait_Command
setPINA 0x80
continue 2
expectPORTB 0x00
checkResult


