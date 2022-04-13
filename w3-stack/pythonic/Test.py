from sqlalchemy import false
from ListStack import ListStack
from ArrayStack import ArrayStack

def htmlParser(html):
    '''expects a valid list of html paired tags in argument'''
    ok = True
    st = ListStack()
    for tag in html:
        if tag[1] == '/':
            if st.length() > 0 and st.top() == tag[2:-1]:
                st.pop()
            else:
                ok = False
                break
        else:
            st.push(tag[1:-1])
    if st.length() > 0:
        ok = False
    return ok

print(htmlParser(['<html>','<head>','</head>','<body>','<p>','</p>','</body>','</html>']))