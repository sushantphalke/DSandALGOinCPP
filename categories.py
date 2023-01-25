categories_list = ['GOPENS', 'GSCS', 'GSTS', 'GVJS', 'GNT1S', 'GNT2S', 'GNT3S',
                   'GOBCS', 'LOPENS', 'LSCS', 'LSTS', 'LVJS', 'LNT1S', 'LNT2S',
                   'LOBCS', 'PWDOPENS', 'DEFOPENS', 'TFWS', 'DEFROBCS', 'EWS',
                   'PWDROBC', 'SDEFROBCS', 'PWDRSCS', 'DEFRSCS', 'DEFOBCS', 'MI',
                   'LNT3S', 'DEFRNT2S']
for i in categories_list:
    categories_list.append(i[:-1]+'H')
    categories_list.append(i[:-1]+'O')
# for i in categories_list:
    print(i)
