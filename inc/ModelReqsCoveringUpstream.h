/*!
 * \file ModelReqsCoveringUpstream.h
 * \brief Definition of the class ModelReqsCoveringUpstream
 * \date 2016-07-29
 * \author f.souliers
 */

#ifndef MODELREQSCOVERINGUPSTREAM_H_
#define MODELREQSCOVERINGUPSTREAM_H_

#include <QAbstractItemModel>

#include "RequirementFileAbstract.h"


/*!
 * \class ModelReqsCoveringUpstream
 * \brief Model (see Qt Framework and MVC) used to display the list of requirements having upstream ones
 */
class ModelReqsCoveringUpstream : public QAbstractItemModel
{
Q_OBJECT

public:

	/*!
	 * \brief Constructor of the model, does nothing special
	 * \param[in]  parent   Not used
	 */
	ModelReqsCoveringUpstream(QObject *parent = Q_NULLPTR);

	/*!
	 * \brief Destructor of the model, does nothing
	 */
	virtual ~ModelReqsCoveringUpstream();

	/*!
	 * \brief Column counter for the model
	 * \see Qt documentation about implementing subclasses of QAbstractItemModel
	 * \param[in] parent  Required by the framework, but not used here
	 * \return
	 * The number of columns the model has
	 */
	int columnCount(const QModelIndex &parent = QModelIndex()) const;

	/*!
	 * \brief Row counter for the model
	 * \see Qt documentation about implementing subclasses of QAbstractItemModel
	 * \param[in] parent  Required by the framework, but not used here
	 * \return
	 * The number of rows the model has
	 */
	int rowCount(const QModelIndex &parent = QModelIndex()) const;

	/*!
	 * \brief Getter for data in the model
	 * \param[in] index  Model index (that is row & column) for which the data is required
	 * \param[in] role   Role for which the data is required (see Qt documentation)
	 * \see ModelReqsCoveringUpstream.cpp for the details of the columns
	 * \return
	 * The required data
	 */
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	/*!
	 * \brief Getter for header data in the model
	 *
	 * The approach is totally the same as for the data method, but here only for columns & row headers
	 * \param[in] index       Model index (that is row & column) for which the header data is required
	 * \param[in] orientation Orientation for which the data is required
	 * \param[in] role        Role for which the data is required (see Qt documentation)
	 * \see ModelReqsCoveringUpstream.cpp for the details of the columns
	 * \return
	 * The required data
	 */
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	/*!
	 * \brief Index builder for a given set of row, column & parent
	 * \param[in] row    row number that must be used to create the index
	 * \param[in] column column number that must be used to create the index
	 * \param[in] parent not used in this implementation
	 * \return
	 * A new created index object
	 */
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;

	/*!
	 * \brief Parent getter for a given index
	 * \param[in] index  Not used in this implementation
	 * \return
	 * An empty index
	 */
	QModelIndex parent(const QModelIndex &index) const;

	/*!
	 * \brief Method used to fill the model with data
	 * \param[in] p_reqs  Vector of pointers to requirements that must be added to the model. This vector is
	 *                    supposed to contain all of the requirements defined in a given file
	 * \warning Only the requirements having upstream requirements (that is covering other requirements) will
	 *          be taken into account
	 */
	void addRequirementsOfAFile(const QVector<Requirement*>& p_reqs);

	/*!
	 * \brief empty __requirements, mainly because new ones are going to be displayed
	 */
	void clear()
	{
		__requirements.clear();
	}

	/*!
	 * \brief Ask for a refresh of the model so the UI is updated
	 *
	 * this method emits the dataChanged and layoutChanged signals so the Qt framework updates the graphical
	 * view associated to this model.
	 */
	void refresh();

private:

	/*!
	 * \brief Vector of the requirements contained in the model
	 */
	QMap<QString, Requirement*> __requirements;
};

#endif /* MODELREQSCOVERINGUPSTREAM_H_ */
