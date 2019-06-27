# Test sequence from B0_LED_ON: A0 => PORTB: 0x02
test "PINA: 0x01 => PORTB: 0x02, state: B1_LED_ON"
set state = B0_LED_ON
setPINA 0x01
continue 2
expectPORTB 0x02
checkResult

# Test sequence from B1_LED_ON: A0 => PORTB: 0x01
test "PINA: 0x01 => PORTB: 0x01, state: B0_LED_ON"
set state = B1_LED_ON
setPINA 0x01
continue 2
expectPORTB 0x01
checkResult
