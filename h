def calculate(rectangles):
    events = []
    ys = set()

    for x1, y1, x2, y2 in rectangles:
        events.append((x1, 1, y1, y2))
        events.append((x2, -1, y1, y2))
        ys.add(y1)
        ys.add(y2)

    ys = sorted(ys)
    y_i = {y:i for i,y in enumerate(ys)}

    seg = [0]*(len(ys)*4)
    count = [0]*(len(ys)*4)

    def update(node, l, r, ql, qr, val):
        if qr <= l or r <= ql:
            return
        if ql <= l and r <= qr:
            count[node] += val
        else:
            mid = (l+r)//2
            update(node*2,l,mid,ql,qr,val)
            update(node*2+1,mid,r,ql,qr,val)

        if count[node]:
            seg[node] = ys[r] - ys[l]
        else:
            if r-l == 1:
                seg[node] = 0
            else:
                seg[node] = seg[node*2] + seg[node*2+1]

    events.sort()

    prev_x = events[0][0]
    area = 0

    for x, typ, y1, y2 in events:
        area += seg[1] * (x - prev_x)
        update(1,0,len(ys)-1,y_i[y1],y_i[y2],typ)
        prev_x = x

    return area