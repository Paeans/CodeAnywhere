
# Paste your code into this box
balance = 99999999999
annualInterestRate = 0.18
monthRate = annualInterestRate / 12.0
lowPay = round(balance / 12.0 * 100.0) / 100.0
highPay = round(balance * (1 + monthRate) ** 12 / 12.0 * 100.0) / 100.0

while round((highPay - lowPay) * 100) > 1:
    remaining = balance
    midPay = round( (lowPay + highPay) / 2 * 100.0 ) / 100.0
    print num, lowPay, highPay, midPay
    num += 1
    for i in range(1, 13):
        remaining = (remaining - midPay) * (1 + monthRate)
    if remaining < 0:
        highPay = midPay
    elif remaining > 0:
        lowPay = midPay
    else:
        print 'YES'
        break
        
print 'Lowest Payment: ' + str(highPay)