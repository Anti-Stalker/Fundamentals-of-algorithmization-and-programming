from typing import *

if TYPE_CHECKING:
    from ptrSQL.ast import Identifier, Ty


class Column:
    """
    Representation of a column in a row set. Contained by `RowSet` instances.
    """

    __slots__ = ['table', 'name', 'ty']

    def __init__(self, table: 'Identifier', name: 'Identifier', ty: 'Ty'):
        self.table = table
        self.name = name
        self.ty = ty
